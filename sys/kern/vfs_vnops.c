/*	fio.c	4.25	82/07/17	*/

#include "../h/param.h"
#include "../h/systm.h"
#include "../h/dir.h"
#include "../h/user.h"
#include "../h/fs.h"
#include "../h/file.h"
#include "../h/conf.h"
#include "../h/inode.h"
#include "../h/reg.h"
#include "../h/acct.h"
#include "../h/mount.h"
#include "../h/socket.h"
#include "../h/socketvar.h"
#include "../h/proc.h"
#ifdef EFS
#include "../net/in.h"
#include "../h/efs.h"
#endif

/*
 * Openi called to allow handler
 * of special files to initialize and
 * validate before actual IO.
 */
#ifdef EFS
openi(ip, rw, trf)
#else
openi(ip, rw)
#endif
	register struct inode *ip;
{
	dev_t dev;
	register unsigned int maj;

	dev = (dev_t)ip->i_rdev;
	maj = major(dev);
	switch (ip->i_mode&IFMT) {

	case IFCHR:
		if (maj >= nchrdev)
			goto bad;
#ifdef EFS
		(*cdevsw[maj].d_open)(dev, rw, trf);
#else
		(*cdevsw[maj].d_open)(dev, rw);
#endif
		break;

	case IFBLK:
		if (maj >= nblkdev)
			goto bad;
		(*bdevsw[maj].d_open)(dev, rw);
	}
	return;

bad:
	u.u_error = ENXIO;
}

/*
 * Check mode permission on inode pointer.
 * Mode is READ, WRITE or EXEC.
 * In the case of WRITE, the
 * read-only status of the file
 * system is checked.
 * Also in WRITE, prototype text
 * segments cannot be written.
 * The mode is shifted to select
 * the owner/group/other fields.
 * The super user is granted all
 * permissions.
 */
access(ip, mode)
	register struct inode *ip;
	int mode;
{
	register m;

	m = mode;
	if (m == IWRITE) {
		if (ip->i_fs->fs_ronly != 0) {
			u.u_error = EROFS;
			return (1);
		}
		if (ip->i_flag&ITEXT)		/* try to free text */
			xrele(ip);
		if (ip->i_flag & ITEXT) {
			u.u_error = ETXTBSY;
			return (1);
		}
	}
	if (u.u_uid == 0)
		return (0);
	if (u.u_uid != ip->i_uid) {
		m >>= 3;
		if (ip->i_gid >= NGRPS ||
		    (u.u_grps[ip->i_gid/(sizeof(int)*8)] &
		     (1 << ip->i_gid%(sizeof(int)*8)) == 0))
			m >>= 3;
	}
	if ((ip->i_mode&m) != 0)
		return (0);
	u.u_error = EACCES;
	return (1);
}

/*
 * Look up a pathname and test if
 * the resultant inode is owned by the
 * current user.
 * If not, try for super-user.
 * If permission is granted,
 * return inode pointer.
 */
struct inode *
owner(follow)
	int follow;
{
	register struct inode *ip;

	ip = namei(uchar, 0, follow);
	if (ip == NULL)
		return (NULL);
#ifdef EFS
	/*
	 * References to extended file system are
	 * returned to the caller.
	 */
	if (efsinode(ip))
		return (ip);
#endif
	if (u.u_uid == ip->i_uid)
		return (ip);
	if (suser())
		return (ip);
	iput(ip);
	return (NULL);
}

/*
 * Test if the current user is the
 * super user.
 */
suser()
{

	if (u.u_uid == 0) {
		u.u_acflag |= ASU;
		return (1);
	}
	u.u_error = EPERM;
	return (0);
}

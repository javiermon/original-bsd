#ifndef lint
static	char *sccsid = "@(#)wwtty.c	3.6 84/03/03";
#endif

#include "ww.h"
#include <fcntl.h>

wwgettty(d, t)
register struct ww_tty *t;
{
	if (ioctl(d, (int)TIOCGETP, (char *)&t->ww_sgttyb) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCGETC, (char *)&t->ww_tchars) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCGLTC, (char *)&t->ww_ltchars) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCLGET, (char *)&t->ww_lmode) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCGETD, (char *)&t->ww_ldisc) < 0)
		goto bad;
	if ((t->ww_fflags = fcntl(d, F_GETFL, 0)) < 0)
		goto bad;
	return 0;
bad:
	wwerrno = WWE_SYS;
	return -1;
}

wwsettty(d, t)
register struct ww_tty *t;
{
	if (ioctl(d, (int)TIOCSETN, (char *)&t->ww_sgttyb) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCSETC, (char *)&t->ww_tchars) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCSLTC, (char *)&t->ww_ltchars) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCLSET, (char *)&t->ww_lmode) < 0)
		goto bad;
	if (ioctl(d, (int)TIOCSETD, (char *)&t->ww_ldisc) < 0)
		goto bad;
	if (fcntl(d, F_SETFL, t->ww_fflags) < 0)
		goto bad;
	return 0;
bad:
	wwerrno = WWE_SYS;
	return -1;
}

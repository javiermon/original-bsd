#	@(#)Makefile	8.1 (Berkeley) 06/10/93

LIB=	sa
SRCS=	bmap.c close.c dev.c getfile.c gets.c ioctl.c lseek.c open.c \
	printf.c read.c stat.c sys.c write.c
.PATH:	../../../stand.att
NOPROFILE=noprofile

.include <bsd.lib.mk>

CFLAGS+=-I.. -I../../..

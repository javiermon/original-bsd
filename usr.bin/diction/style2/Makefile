#	@(#)Makefile	8.1 (Berkeley) 06/06/93

PROG=	style2
CFLAGS+=-I${.CURDIR} -I${.CURDIR}/../style1
SRCS=	style2.c
CLEANFILES=style2.c
DPADD=	${LIBL}
LDADD=	-ll
NOMAN=	noman
BINDIR=	/usr/libexec

.include <bsd.prog.mk>

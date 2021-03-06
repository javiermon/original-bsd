/*
 * Copyright (c) 1983, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#if defined(SYSLIBC_SCCS) && !defined(lint)
	.asciz "@(#)fork.s	8.1 (Berkeley) 06/04/93"
#endif /* SYSLIBC_SCCS and not lint */

#include "SYS.h"

SYSCALL(fork)
	bitl	$1,r1
	beql	1f	# parent, since r1 == 0 in parent, 1 in child
	clrl	r0
1:
	ret		# pid = fork()

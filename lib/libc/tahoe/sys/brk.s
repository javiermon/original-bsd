/*
 * Copyright (c) 1983, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#if defined(SYSLIBC_SCCS) && !defined(lint)
	.asciz "@(#)brk.s	8.1 (Berkeley) 06/04/93"
#endif /* SYSLIBC_SCCS and not lint */

#include "SYS.h"

#define	SYS_brk		17

	.globl	curbrk
	.globl	minbrk

ENTRY(brk)
	cmpl	4(fp),minbrk
	bgeq	ok
	movl	minbrk,4(fp)
ok:
	kcall	$SYS_brk
	jcs	err
	movl	4(fp),curbrk
	clrl	r0
	ret
err:
	jmp	cerror

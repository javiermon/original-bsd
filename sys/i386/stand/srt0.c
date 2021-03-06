/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * William Jolitz.
 *
 * %sccs.include.redist.c%
 *
 *	@(#)srt0.c	8.1 (Berkeley) 06/11/93
 */

/*
 * Startup code for standalone system
 * Non-relocating version -- for programs which are loaded by boot
 * Relocating version for boot
 * Small relocating version for "micro" boot
 */

	.globl	_end
	.globl	_edata
	.globl	_main
	.globl	__rtt
	.globl	_exit
	.globl	_bootdev
	.globl	_cyloffset

#ifdef SMALL
	/* where the disklabel goes if we have one */
	.globl	_disklabel
_disklabel:
	.space 512
#endif

entry:	.globl	entry
	.globl	start

#if	defined(REL) && !defined(SMALL)

	/* relocate program and enter at symbol "start" */

	#movl	$entry-RELOC,%esi	# from beginning of ram
	movl	$0,%esi
	#movl	$entry,%edi		# to relocated area
	movl	$ RELOC,%edi		# to relocated area
	# movl	$_edata-RELOC,%ecx	# this much
	movl	$64*1024,%ecx
	cld
	rep
	movsb
	# relocate program counter to relocation base
	pushl	$start
	ret
#endif

start:

	/* setup stack pointer */

#ifdef REL
	leal	4(%esp),%eax	/* ignore old pc */
	movl	$ RELOC-4*4,%esp
	/* copy down boot parameters */
	movl	%esp,%ebx
	pushl	$3*4
	pushl	%ebx
	pushl	%eax
	call	_bcopy
	movl	%ebx,%esp
#else
	/* save old stack state */
	movl	%esp,savearea
	movl	%ebp,savearea+4
	movl	$ RELOC-0x2400,%esp
#endif

	/* clear memory as needed */

	movl	%esp,%esi
#ifdef	REL

	/*
	 * Clear Bss and up to 64K heap
	 */
	movl	$64*1024,%ebx
	movl	$_end,%eax	# should be movl $_end-_edata but ...
	subl	$_edata,%eax
	addl	%ebx,%eax
	pushl	%eax
	pushl	$_edata
	call	_bzero

	/*
	 * Clear 64K of stack
	 */
	movl	%esi,%eax
	subl	%ebx,%eax
	subl	$5*4,%ebx
	pushl	%ebx
	pushl	%eax
	call	_bzero
#else
	movl	$_edata,%edx
	movl	%esp,%eax
	subl	%edx,%eax
	pushl	%edx
	pushl	%esp
	call	_bzero
#endif
	movl	%esi,%esp

	pushl	$0
	popf

#ifndef	SMALL
	call	_kbdreset	/* resets keyboard and gatea20 brain damage */
#endif

	call	_main
	jmp	1f

	.data
_bootdev:	.long	0
_cyloffset:	.long	0
savearea:	.long	0,0	# sp & bp to return to
	.text
#ifndef	SMALL
	.globl _getchar
#endif
	.globl _wait

__rtt:
#ifndef	SMALL
	call	_getchar
#else
_exit:
	pushl	$1000000
	call	_wait
	popl	%eax
#endif
	movl	$-7,%eax
	jmp	1f
#ifndef	SMALL
_exit:
	call	_getchar
#endif
	movl	4(%esp),%eax
1:
#ifdef	REL
#ifndef SMALL
	call	_reset_cpu
#endif
	movw	$0x1234,%ax
	movw	%ax,0x472	# warm boot
	movl	$0,%esp		# segment violation
	ret
#else
	movl	savearea,%esp
	movl	savearea+4,%ebp
	ret
#endif

	.globl	_inb
_inb:	movl	4(%esp),%edx
	subl	%eax,%eax	# clr eax
	inb	%dx,%al
	ret

	.globl	_outb
_outb:	movl	4(%esp),%edx
	movl	8(%esp),%eax
	outb	%al,%dx
	ret

	.globl ___udivsi3
___udivsi3:
	movl 4(%esp),%eax
	xorl %edx,%edx
	divl 8(%esp)
	ret

	.globl ___divsi3
___divsi3:
	movl 4(%esp),%eax
	xorl %edx,%edx
	cltd
	idivl 8(%esp)
	ret

	#
	# bzero (base,cnt)
	#

	.globl _bzero
_bzero:
	pushl	%edi
	movl	8(%esp),%edi
	movl	12(%esp),%ecx
	movb	$0x00,%al
	cld
	rep
	stosb
	popl	%edi
	ret

	#
	# bcopy (src,dst,cnt)
	# NOTE: does not (yet) handle overlapped copies
	#

	.globl	_bcopy
_bcopy:
	pushl	%esi
	pushl	%edi
	movl	12(%esp),%esi
	movl	16(%esp),%edi
	movl	20(%esp),%ecx
	cld
	rep
	movsb
	popl	%edi
	popl	%esi
	ret

	# insw(port,addr,cnt)
	.globl	_insw
_insw:
	pushl	%edi
	movw	8(%esp),%dx
	movl	12(%esp),%edi
	movl	16(%esp),%ecx
	cld
	nop
	.byte 0x66,0xf2,0x6d	# rep insw
	nop
	movl	%edi,%eax
	popl	%edi
	ret

	# outsw(port,addr,cnt)
	.globl	_outsw
_outsw:
	pushl	%esi
	movw	8(%esp),%dx
	movl	12(%esp),%esi
	movl	16(%esp),%ecx
	cld
	nop
	.byte 0x66,0xf2,0x6f	# rep outsw
	nop
	movl	%esi,%eax
	popl	%esi
	ret


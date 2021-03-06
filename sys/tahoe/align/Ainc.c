/*-
 * Copyright (c) 1986 The Regents of the University of California.
 * All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Computer Consoles Inc.
 *
 * %sccs.include.redist.c%
 *
 *	@(#)Ainc.c	7.1 (Berkeley) 12/06/90
 */

#include "align.h" 
inc(infop)	process_info *infop;
/*
/*	Increment operand.
/*
/***************************************/
{
	register	long	Register_12;	/* Has to be first reg ! */
	register	long	Register_11;

	Register_11 = operand(infop,0)->data;
	Register_12=psl;
	Set_psl(r12);	/* restore the user psl */
	asm ("	incl	r11");			/* Make sure to use the
						 * right opcode */
	asm ("	movpsl	r12");
	New_cc (Register_12);

	write_back (infop,Register_11, operand(infop,0) );
}	

/* Copyright (c) 1979 Regents of the University of California */

#ifndef lint
static	char sccsid[] = "@(#)opc.c 2.1 02/08/84";
#endif

#include "OPnames.h"

main()  {
	register int i;

	for (i = 0;  i < 256;  i++)
		if (otext[i])
			printf("#define O_%s %04o\n", otext[i]+1, i);
	exit(0);
}

/*-
 * Copyright (c) 1982, 1988 The Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.proprietary.c%
 *
 *	@(#)sys.c	7.16 (Berkeley) 05/05/91
 */

#include <sys/param.h>
#include <sys/reboot.h>
#include <ufs/dir.h>
#include "saio.h"

struct iob iob[SOPEN_MAX];
int errno;

#ifndef i386
exit()
{
	_stop("Exit called");
}
#endif

_stop(s)
	char *s;
{
	static int stopped;
	int i;

	if (!stopped) {
		stopped = 1;
		for (i = 0; i < SOPEN_MAX; i++)
			if (iob[i].i_flgs != 0)
				(void)close(i);
	}
	printf("%s\n", s);
	_rtt();
}

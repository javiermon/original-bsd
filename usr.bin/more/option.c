/*
 * Copyright (c) 1988 Mark Nudleman
 * Copyright (c) 1988 Regents of the University of California.
 * All rights reserved.
 *
 * %sccs.include.redist.c%
 */

#ifndef lint
static char sccsid[] = "@(#)option.c	5.11 (Berkeley) 06/01/90";
#endif /* not lint */

#include <stdio.h>
#include <less.h>

int top_scroll;			/* Repaint screen from top */
int bs_mode;			/* How to process backspaces */
int caseless;			/* Do "caseless" searches */
int cbufs = 10;			/* Current number of buffers */
int linenums = 1;		/* Use line numbers */
int quit_at_eof;
int squeeze;			/* Squeeze multiple blank lines into one */
int tabstop = 8;		/* Tab settings */
int tagoption;

char *firstsearch;
extern int sc_height;

option(argc, argv)
	int argc;
	char **argv;
{
	extern char *optarg;
	extern int optind;
	static int sc_window_set = 0;
	int ch;
	char *p;

	/* backward compatible processing for "+/search" */
	char **a;
	for (a = argv; *a; ++a)
		if ((*a)[0] == '+' && (*a)[1] == '/')
			(*a)[0] = '-';

	optind = 1;		/* called twice, re-init getopt. */
	while ((ch = getopt(argc, argv, "0123456789/:ceinst:ux:f")) != EOF)
		switch((char)ch) {
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			/*
			 * kludge: more was originally designed to take
			 * a number after a dash.
			 */
			if (!sc_window_set) {
				p = argv[optind - 1];
				if (p[0] == '-' && p[1] == ch && !p[2])
					sc_height = atoi(++p);
				else
					sc_height = atoi(argv[optind] + 1);
				sc_window_set = 1;
			}
			break;
		case '/':
			firstsearch = optarg;
			break;
		case 'c':
			top_scroll = 1;
			break;
		case 'e':
			quit_at_eof = 1;
			break;
		case 'i':
			caseless = 1;
			break;
		case 'n':
			linenums = 0;
			break;
		case 's':
			squeeze = 1;
			break;
		case 't':
			tagoption = 1;
			findtag(optarg);
			break;
		case 'u':
			bs_mode = 1;
			break;
		case 'x':
			tabstop = atoi(optarg);
			if (tabstop <= 0)
				tabstop = 8;
			break;
		case 'f':	/* ignore -f, compatability with old more */
			break;
		case '?':
		default:
			fprintf(stderr,
			    "usage: more [-ceinus] [-t tag] [-x tabs] [-/ pattern] [-#] [file ...]\n");
			exit(1);
		}
	return(optind);
}

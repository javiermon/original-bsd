divert(-1)
#
# Copyright (c) 1983 Eric P. Allman
# Copyright (c) 1988, 1993
#	The Regents of the University of California.  All rights reserved.
#
# %sccs.include.redist.sh%
#

#
#  This is the prototype for a configuration that only supports UUCP
#  and does not have DNS support at all.
#
#  You MUST change the `OSTYPE' macro to specify the operating system
#  on which this will run; this will set the location of various
#  support files for your operating system environment.  You MAY
#  create a domain file in ../domain and reference it by adding a
#  `DOMAIN' macro after the `OSTYPE' macro.  I recommend that you
#  first copy this to another file name so that new sendmail releases
#  will not trash your changes.
#

include(`../m4/cf.m4')
VERSIONID(`@(#)uucpproto.mc	8.4 (Berkeley) 04/21/95')
OSTYPE(unknown)
FEATURE(nodns)dnl
MAILER(local)dnl
MAILER(uucp)dnl

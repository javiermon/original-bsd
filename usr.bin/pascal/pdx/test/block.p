(*
 * Copyright (c) 1980, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * %sccs.include.redist.c%
 *
 *	@(#)block.p	8.1 (Berkeley) 06/06/93
 *)

program blocktest(input, output);
procedure A;
	procedure B;
	begin
		writeln('in procedure B');
	end;
begin
	writeln('in procedure A');
	B;
end;

begin
	writeln('in main program');
	A;
end.

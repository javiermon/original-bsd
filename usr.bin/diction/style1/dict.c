/*-
 * %sccs.include.proprietary.c%
 *
 *	@(#)dict.c	8.1 (Berkeley) 06/06/93
 */

struct dict  dict[] = {
"a",'A',
"an",'A',
"the",'A',
"can",'x',
"cannot",'x',
"could",'x',
"did",'x',
"do",'z',
"does",'y',
"had",'e',
"have",'g',
"has",'f',
"may",'X',
"might",'X',
"must",'X',
"shall",'X',
"should",'X',
"will",'X',
"would",'X',
"to",'F',
"own",'J',
"am",'c',
"been",'B',
"are",'b',
"be",'B',
"being",'B',
"is",'c',
"was",'c',
"were",'b',
"and",'C',
"but",'C',
"or",'C',
"nor",'C',
"yet",'D',
"no",'J',
"not",'D',
"his",'O',
"her",'O',
"its",'O',
"my",'O',
"our",'O',
"their",'O',
"your",'O',
"above",'P',
"aboard",'P',
"across",'P',
"after",'p',
"against",'P',
"along",'P',
"amid",'P',
"among",'P',
"around",'P',
"as",'p',
"at",'P',
"before",'p',
"beneath",'P',
"behind",'P',
"below",'P',
"beside",'p',
"besides",'P',
"between",'P',
"beyond",'P',
"by",'P',
"down",'P',
"during",'P',
"except",'P',
"for",'p',
"from",'P',
"in",'P',
"inside",'P',
"into",'P',
"onto",'P',
"like",'p',
"near",'P',
"of",'P',
"off",'P',
"on",'P',
"outside",'P',
"over",'P',
"past",'J',
"per",'P',
"through",'P',
"till",'P',
"toward",'P',
"towards",'P',
"under",'P',
"until",'p',
"up",'P',
"upon",'P',
"via",'P',
"with",'P',
"within",'P',
"without",'P',
"I",'K',
"he",'K',
"it",'K',
"me",'R',
"us",'R',
"him",'R',
"them",'R',
"hers",'R',
"theirs",'R',
"mine",'R',
"none",'R',
"one",'a',
"ours",'R',
"she",'K',
"there",'R',
"these",'W',
"they",'R',
"this",'a',
"those",'W',
"we",'R',
"who",'w',
"whoever",'w',
"whom",'S',
"whose",'R',
"you",'R',
"yours",'R',
"anyone",'K',
"everyone",'K',
"someone",'K',
"anybody",'K',
"everybody",'K',
"somebody",'K',
"nobody",'K',
"anything",'K',
"nothing",'K',
"something",'K',
"everything",'K',
"everywhere",'L',
"anywhere",'K',
"nowhere",'L',
"somewhere",'L',
"someplace",'K',
"noplace",'K',
"anyplace",'K',
"everyplace",'K',
"enough",'W',
"few",'W',
"less",'W',
"much",'W',
"more",'W',
"most",'W',
"other",'a',
"others",'W',
"another",'a',
"some",'W',
"either",'a',
"neither",'a',
"several",'W',
"all",'W',
"both",'W',
"each",'a',
"many",'W',
"myself",'R',
"yourself",'R',
"himself",'R',
"herself",'R',
"itself",'R',
"yourselves",'R',
"themselves",'R',
"although",'S',
"because",'S',
"however",'S',
"if",'S',
"once",'S',
"since",'p',
"so",'D',
"though",'S',
"unless",'S',
"when",'S',
"whenever",'S',
"whatever",'S',
"while",'S',
"where",'S',
"why",'S',
"how",'S',
"what",'T',
"inasmuch",'S',
"whereas",'S',
"wherever",'S',
"whereby",'S',
"that",'T',
"which",'T',
"moreover",'S',
"furthermore",'S',
"therefore",'S',
"hence",'S',
"nevertheless",'S',
"otherwise",'S',
"afterwards",'S',
"than",'S',
"still",'S',
"also",'D',
"thus",'D',
"sometimes",'D',
"sometime",'D',
"someday",'D',
"already",'D',
"alright",'D',
"too",'D',
"able",'J',
"such",'J',
"same",'G',
"single",'J',
"little",'G',
"any",'G',
"half",'G',
"double",'Y',
"every",'J',
"almost",'D',
"about",'p',
"then",'D',
"soon",'D',
"fast",'G',
"well",'G',
"often",'D',
"here",'D',
"now",'D',
"always",'D',
"never",'D',
"maybe",'D',
"perhaps",'D',
"very",'G',
"quite",'D',
"rather",'D',
"just",'G',
"even",'G',
"least",'G',
"first",'G',
"long",'G',
"back",'G',
"next",'G',
"far",'G',
"last",'G',
"elsewhere",'D',
"throughout",'p',
"away",'G',
"somewhat",'D',
"today",'L',
"tomorrow",'L',
"crept",'d',
"kept",'d',
"leapt",'d',
"slept",'d',
"swept",'d',
"wept",'d',
"made",'d',
"won",'d',
"sang",'d',
"heard",'d',
"drove",'d',
"wrote",'d',
"built",'d',
"dealt",'d',
"felt",'d',
"stung",'d',
"clung",'d',
"flung",'d',
"hung",'d',
"rung",'d',
"strung",'d',
"swung",'d',
"wrung",'d',
"spun",'d',
"rode",'d',
"rang",'d',
"swam",'d',
"sprang",'d',
"saw",'d',
"sat",'d',
"rose",'d',
"gave",'d',
"grew",'d',
"drank",'d',
"bought",'d',
"fought",'d',
"brought",'d',
"caught",'d',
"sought",'d',
"taught",'d',
"thought",'d',
"sung",'d',
"driven",'d',
"written",'d',
"ridden",'d',
"swum",'d',
"seen",'d',
"risen",'d',
"drunk",'d',
"ought",'V',
"ago",'G',
"out",'G',
"again",'D',
"began",'d',
"begun",'d',
"bent",'d',
"bound",'d',
"bit",'d',
"bitten",'d',
"blew",'d',
"blown",'d',
"broke",'d',
"broken",'d',
"chose",'d',
"came",'d',
"dug",'d',
"drew",'d',
"drawn",'d',
"ate",'d',
"eaten",'d',
"fell",'d',
"fallen",'d',
"fed",'d',
"found",'d',
"flew",'d',
"flown",'d',
"forgot",'d',
"forgotten",'d',
"froze",'d',
"frozen",'d',
"got",'d',
"gotten",'d',
"given",'d',
"went",'d',
"gone",'d',
"grown",'d',
"hid",'d',
"hidden",'d',
"held",'d',
"beheld",'d',
"knelt",'d',
"knew",'d',
"known",'d',
"laid",'d',
"led",'d',
"lent",'d',
"lay",'d',
"lain",'d',
"lit",'d',
"lost",'d',
"meant",'d',
"met",'d',
"mistook",'d',
"mistaken",'d',
"paid",'d',
"ran",'d',
"said",'v',
"sold",'d',
"sent",'d',
"shook",'d',
"shaken",'d',
"shone",'d',
"shown",'d',
"shrank",'d',
"shrunk",'d',
"sank",'d',
"sunk",'d',
"slid",'d',
"slung",'d',
"spoke",'d',
"spoken",'d',
"spent",'d',
"stood",'d',
"spread",'d',
"stole",'d',
"stolen",'d',
"stuck",'d',
"struck",'d',
"swore",'d',
"sworn",'d',
"swollen",'d',
"took",'d',
"taken",'d',
"tore",'d',
"torn",'d',
"told",'v',
"threw",'d',
"thrown",'d',
"understood",'d',
"wore",'d',
"worn",'d',
"wove",'d',
"woven",'d',
"wound",'d',
"run",'d',
"gas",'U',
"whether",'S',
"done",'d',
"became",'d',
"chosen",'d',
"come",'d',
"become",'d',
"children",'n',
"people",'n',
"ever",'D',
"according",'P',
"unpaid",'d',
"interwoven",'d',
"color",'Z',
"together",'D',
"left",'d',
"set",'d',
"born",'d',
"cut",'d',
"put",'d',
"sent",'d',
"altogether",'D',
"unchanged",'J',
"forth",'D',
"upheld",'d',
"therewith",'D',
"instead",'D',
"ah",'i',
"aha",'i',
"ay",'i',
"bah",'i',
"boo",'i',
"eh",'i',
"gee",'i',
"ha",'i',
"hey",'i',
"hi",'i',
"ho",'i',
"hurrah",'i',
"oh",'i',
"ouch",'i',
"rah",'i',
"sh",'i',
"ugh",'i',
"whee",'i',
"woe",'i',
"wow",'i',
"ready",'J',
"deep",'J',
"alone",'J',
"old",'J',
"ahead",'D',
"better",'G',
"overlaid",'d',
"later",'G',
"abroad",'D',
"further",'G',
"heavy",'J',
"major",'U',
"series",'N',
"great",'J',
"overseas",'G',
"afterward",'S',
"award",'Z',
"coward",'N',
"forward",'U',
"steward",'Z',
"ward",'Z',
"x",'N',
0, 0
};

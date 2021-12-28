	.text
start:
	sp.H = _stack;
	sp.L = _stack;
	call _main;
	nop;

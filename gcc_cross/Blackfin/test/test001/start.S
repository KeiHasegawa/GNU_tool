	.text
start:
	R0.H = _bss_start;
	R0.L = _bss_start;
	R1.H = _bss_end;
	R1.L = _bss_end;
	R2 = 0 (X);
.L1:
	cc =R0==R1;
	if cc jump .L2;
	P2 = R0;
	B [P2] = R2;
	R0 += 1;
	jump .L1;
.L2:	
	sp.H = _stack;
	sp.L = _stack;
	call _main;
	nop;

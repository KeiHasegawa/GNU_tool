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
	.word	0xeef0

	.global	_printf
_printf:
	.word	0xeef1
	rts;

	.global	_puts
_puts:
	.word	0xeef2
	rts;

	.global	_putchar
_putchar:
	.word	0xeef3
	rts;

.global _memcpy;
_memcpy:
	LINK 4;
	[FP+8] = R0;
	[FP+12] = R1;
	[FP+16] = R2;
	R0 = [FP+8];
	[FP+-4] = R0;
	jump.s .L10;
.L11:
	P1 = [FP+12];
	R0 = P1;
	R0 += 1;
	[FP+12] = R0;
	P2 = [FP+8];
	R0 = P2;
	R0 += 1;
	[FP+8] = R0;
	R0 = B [P1] (X);
	B [P2] = R0;
.L10:
	R0 = [FP+16];
	R1 = R0;
	R1 += -1;
	[FP+16] = R1;
	cc =R0==0;
	if !cc jump .L11;
	R0 = [FP+-4];
	UNLINK;
	rts;
	

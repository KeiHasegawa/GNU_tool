	.text
start:
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

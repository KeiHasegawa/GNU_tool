	.text
start:
	movw	$stack,sp
	bal (ra), _main@c
	nop
	.word	0x80f0

	.global	_printf
_printf:
	.word	0x80f1
	jump	 (ra)

	.global	_puts
_puts:
	.word	0x80f2
	jump	 (ra)

	.global	_putchar
_putchar:
	.word	0x80f3
	jump	 (ra)
	

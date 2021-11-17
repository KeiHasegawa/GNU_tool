	.text
start:
	move.d _stack,$sp
	jsr _main
	nop
	.word	0xfdb0
	
	.global	_printf
_printf:
	ret

	.global	_puts
_puts:
	ret

	.global	_putchar
_putchar:
	ret
	
	

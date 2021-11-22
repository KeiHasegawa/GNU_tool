	.text
start:
	movw	sp, #stack
	call	!!%code(_main)
	nop
	.short	0x0631
	
	.global	_printf
_printf:
	.short	0x1631
	ret

	.global	_puts
_puts:
	.short	0x2631
	ret

	.global	_putchar
_putchar:
	.short	0x3631
	ret
	

	.text
	.global start
start:
	nop
	mov.L	#_stack, r0
	bsr	_main
	nop
	.byte	0x30

	.global	_printf
_printf:
	.byte	0x31
	rts

	.global	_puts
_puts:
	.byte	0x32
	rts

	.global	_putchar
_putchar:
	.byte	0x33
	rts
	



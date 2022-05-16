	.text
start:
	mov	$stack, sp
	jsr	pc, _main
	.word	0x0ec0	

	.global	___main
___main:
	rts	pc

	.global	_printf
_printf:
	.word	0x0ec1
	rts	pc

	.global	_puts
_puts:
	.word	0x0ec2
	rts	pc

	.global	_putchar
_putchar:
	.word	0x0ec3 
	rts	pc

	.text
start:
	ldconst	stack, g4
	mov	g4, sp
	mov	g4, fp
	callx	_main
	.word	0xbadbeef0

	.global	___main
___main:
	ret

	.global _printf
_printf:
	.word	0xbadbeef1
	ret

	.global _puts
_puts:
	.word	0xbadbeef2
	ret
	
	.global _putchar
_putchar:
	.word	0xbadbeef3
	ret

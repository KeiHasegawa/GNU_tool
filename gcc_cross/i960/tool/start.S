	.text
start:
	ldconst	_bss_start, g4
	ldconst	_bss_end, g5
	mov	0, g6
.L1:
	cmpi	g4, g5
	be	.L2
	stob	g6,(g4)
	addo	g4, 1, g4
	b	.L1
.L2:
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
	ret

	.global _puts
_puts:
	ret
	
	.global _putchar
_putchar:
	ret

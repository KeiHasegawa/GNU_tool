	.text
	.global _start
_start:
	adrp	x0, _stack
	add	sp, x0, :lo12:_stack
	bl	main
	nop
	.word	0xbadbeef0

	.global printf
printf:
	.word	0xbadbeef1
	ret

	.global vprintf
vprintf:
	.word	0xbadbeef1
	ret

	.global puts
puts:
	.word	0xbadbeef2
	ret

	.global putchar
putchar:
	.word	0xbadbeef3
	ret

	.global	memcpy
memcpy:
	sub	sp, sp, #48
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	str	w2, [sp, 12]
	ldr	x0, [sp, 24]
	str	x0, [sp, 40]
	b	.L10
.L11:
	ldr	x1, [sp, 16]
	add	x0, x1, 1
	str	x0, [sp, 16]
	ldr	x0, [sp, 24]
	add	x2, x0, 1
	str	x2, [sp, 24]
	ldrb	w1, [x1]
	strb	w1, [x0]
.L10:
	ldr	w0, [sp, 12]
	sub	w1, w0, #1
	str	w1, [sp, 12]
	cmp	w0, 0
	bne	.L11
	ldr	x0, [sp, 40]
	add	sp, sp, 48
	ret

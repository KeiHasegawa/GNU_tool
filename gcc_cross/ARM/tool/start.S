	.text
start:
	nop
	ldr	sp, label
	bl	main
	nop
	.word	0xbadbeef0

	.align	2
label:
	.word	stack

	.global	printf
printf:
	.word	0xbadbeef1
	mov	pc, lr

	.global	puts
puts:
	.word	0xbadbeef2
	mov	pc, lr

	.global	putchar
putchar:
	.word	0xbadbeef3
	mov	pc, lr

	.global	vprintf
vprintf:	
	.word	0xbadbeef4
	mov	pc, lr

	.global	memcpy
memcpy:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #16
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	ldr	r3, [fp, #-8]
	str	r3, [fp, #-4]
	b	.L33
.L34:
	ldr	r2, [fp, #-12]
	add	r3, r2, #1
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-8]
	add	r1, r3, #1
	str	r1, [fp, #-8]
	ldrb	r2, [r2]
	strb	r2, [r3]
.L33:
	ldr	r3, [fp, #-16]
	sub	r2, r3, #1
	str	r2, [fp, #-16]
	cmp	r3, #0
	bne	.L34
	ldr	r3, [fp, #-4]
	mov	r0, r3
	add	sp, fp, #0
	ldr	fp, [sp], #4
	bx	lr

	.global	memset
memset:
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #16
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	ldr	r3, [fp, #-8]
	str	r3, [fp, #-4]
	b	.L38
.L39:
	ldr	r3, [fp, #-8]
	add	r2, r3, #1
	str	r2, [fp, #-8]
	ldr	r2, [fp, #-12]
	and	r2, r2, #255
	strb	r2, [r3]
.L38:
	ldr	r3, [fp, #-16]
	sub	r2, r3, #1
	str	r2, [fp, #-16]
	cmp	r3, #0
	bne	.L39
	ldr	r3, [fp, #-4]
	mov	r0, r3
	add	sp, fp, #0
	ldr	fp, [sp], #4
	bx	lr

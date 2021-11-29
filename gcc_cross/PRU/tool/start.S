	.text
start:
	ldi	sp, stack
	call	main
	nop
	.word	0xbadbeef0

	.global	printf
printf:
	.word	0xbadbeef1
	ret

	.global	puts
puts:
	.word	0xbadbeef2
	ret

	.global	putchar
putchar:
	.word	0xbadbeef3
	ret

	.global	memcpy
memcpy:
	sub	r2, r2, 20
	sbbo	r4.b0, r2, 16, 4
	add	r4, r2, 20
	sub	r0, r4, 16
	sbbo	r14.b0, r0, 0, 4
	sub	r0, r4, 12
	sbbo	r15.b0, r0, 0, 4
	sub	r0, r4, 8
	sbbo	r16.b0, r0, 0, 4
	sub	r0, r4, 16
	lbbo	r0.b0, r0, 0, 4
	sub	r1, r4, 20
	sbbo	r0.b0, r1, 0, 4
	jmp	%label(.L13)
.L14:
	sub	r0, r4, 12
	lbbo	r1.b0, r0, 0, 4
	add	r0, r1, 1
	sub	r14, r4, 12
	sbbo	r0.b0, r14, 0, 4
	sub	r0, r4, 16
	lbbo	r0.b0, r0, 0, 4
	add	r14, r0, 1
	sub	r15, r4, 16
	sbbo	r14.b0, r15, 0, 4
	lbbo	r1.b0, r1, 0, 1
	sbbo	r1.b0, r0, 0, 1
.L13:
	sub	r0, r4, 8
	lbbo	r0.b0, r0, 0, 4
	sub	r1, r0, 1
	sub	r14, r4, 8
	sbbo	r1.b0, r14, 0, 4
	qbne	.L14, r0, 0
	sub	r0, r4, 20
	lbbo	r0.b0, r0, 0, 4
	mov	r14, r0
	sub	r2, r4, 4
	lbbo	r4.b0, r2, 0, 4
	add	r2, r2, 4
	ret
	

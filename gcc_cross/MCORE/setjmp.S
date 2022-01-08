	.text
	.global	setjmp
setjmp:
	stw	r8, (r2)
	addi	r2, 4
	stw	r9, (r2)
	addi	r2, 4
	stw	r10, (r2)
	addi	r2, 4
	stw	r11, (r2)
	addi	r2, 4
	stw	r12, (r2) 
	addi	r2, 4
	stw	r13, (r2)
	addi	r2, 4
	stw	r14, (r2)
	addi	r2, 4
	stw	r15, (r2)
	movi	r2, 0
	jmp	r15

	.global longjmp
longjmp:
	ldw	r8, (r2)
	addi	r2, 4
	ldw	r9, (r2)
	addi	r2, 4
	ldw	r10, (r2)
	addi	r2, 4
	ldw	r11, (r2)
	addi	r2, 4
	ldw	r12, (r2)
	addi	r2, 4
	ldw	r13, (r2)
	addi	r2, 4
	ldw	r14, (r2)
	addi	r2, 4
	ldw	r15, (r2)
	movi	r4, 0
	cmpne	r3, r4
	jbt	.L1
	nop
	movi	r3, 1
.L1:
	mov	r2, r3
	jmp	r15

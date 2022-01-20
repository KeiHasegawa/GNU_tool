	.text
	.align	1
	.export	f
	.type	f, @function
f:
	subi	sp,8
	stw	r15,(sp)
	stw	r8,(sp,4)
	subi	sp,8
	mov	r8,sp
	stw	r2,(r8)
	stw	r3,(r8,4)
	
	ldw	r6,(r8)
	ldw	r7,(r8,4)
	addu	r7,r6
	mov	r2,r7
	
	addi	sp, 8
	ldw	r15,(sp)
	ldw	r8,(sp,4)
	jmp	r15

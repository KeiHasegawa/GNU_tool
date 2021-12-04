	.text
start:
	lrw	r6, _bss_start
	lrw	r7, _bss_end
	movi	r8,0
	movi	r9,1
.L1:	
	cmpne	r6, r7
	jbf	.L2
	nop
	st.b	r8,(r6)
	addu	r6, r9
	jbr	.L1
	nop
.L2:	
	lrw	r8, _stack
	mov	sp, r8
	jbsr	main
	nop
	.short 0x09f0

	.global	printf
printf:	
	.short 0x09f1
	jmp r15

	.global	puts
puts:	
	.short 0x09f2
	jmp r15

	.global	putchar
putchar:	
	.short 0x09f3
	jmp r15

	.global	memcpy
memcpy:
	subi	sp,32
	stw	r8,(sp,24)
	mov	r8,sp
	stw	r2,(r8,8)
	stw	r3,(r8,12)
	stw	r4,(r8,16)
	ldw	r7,(r8,8)
	stw	r7,(r8)
	jbr	.L13
.L14:
	ldw	r6,(r8,12)
	movi	r7,1
	addu	r7,r6
	stw	r7,(r8,12)
	ldw	r7,(r8,8)
	movi	r5,1
	addu	r5,r7
	stw	r5,(r8,8)
	ld.b	r6,(r6)
	st.b	r6,(r7)
.L13:
	ldw	r7,(r8,16)
	bmaski	r6,32	// -1 0xffffffffffffffff
	addu	r6,r7
	stw	r6,(r8,16)
	cmpnei	r7,0
	jbt	.L14
	ldw	r7,(r8)
	mov	r2,r7
	mov	sp,r8
	ldw	r8,(sp,24)
	addi	sp,32
	jmp	r15

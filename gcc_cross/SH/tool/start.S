	.text
start:
	nop
	mov.l	label1,r15
	mov.l	label2,r1
	jsr	@r1
	nop
	.word 0xfe50		# simulator or gdb will call exit(0)
	.align 2
label1:
	.long	stack
label2:
	.long	_main
	
	
	.global	_printf
_printf:
	.word 0xfe51
	rts

	.global	_puts
_puts:
	.word 0xfe52
	rts

	.global	_putchar
_putchar:
	.word 0xfe53
	rts


	.global	_memcpy
_memcpy:
	mov.l	r14,@-r15
	add	#-16,r15
	mov	r15,r14
	mov	r14,r1
	add	#-48,r1
	mov.l	r4,@(56,r1)
	mov	r14,r1
	add	#-48,r1
	mov.l	r5,@(52,r1)
	mov	r14,r1
	add	#-48,r1
	mov.l	r6,@(48,r1)
	mov	r14,r1
	add	#-48,r1
	mov	r14,r2
	add	#-48,r2
	mov.l	@(56,r2),r2
	mov.l	r2,@(60,r1)
	bra	.L2
	nop
	.align 1
.L3:
	mov	r14,r1
	add	#-48,r1
	mov.l	@(52,r1),r2
	mov	r14,r1
	add	#-48,r1
	mov	r2,r3
	add	#1,r3
	mov.l	r3,@(52,r1)
	mov	r14,r1
	add	#-48,r1
	mov.l	@(56,r1),r1
	mov	r14,r3
	add	#-48,r3
	mov	r1,r7
	add	#1,r7
	mov.l	r7,@(56,r3)
	mov.b	@r2,r2
	mov.b	r2,@r1
.L2:
	mov	r14,r1
	add	#-48,r1
	mov.l	@(48,r1),r1
	mov	r14,r2
	add	#-48,r2
	mov	r1,r3
	add	#-1,r3
	mov.l	r3,@(48,r2)
	tst	r1,r1
	bf	.L3
	mov	r14,r1
	add	#-48,r1
	mov.l	@(60,r1),r1
	mov	r1,r0
	add	#16,r14
	mov	r14,r15
	mov.l	@r15+,r14
	rts	
	nop
	
	

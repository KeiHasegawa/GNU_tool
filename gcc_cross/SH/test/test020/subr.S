	.text
	.align 1
	.global	_f
_f:
	mov.l	r14,@-r15
	add	#-8,r15
	mov	r15,r14
	mov	r14,r1
	add	#-56,r1
	mov.l	r4,@(60,r1)
	mov	r14,r1
	add	#-56,r1
	mov.l	r5,@(56,r1)
	
	mov	r14,r2
	add	#-56,r2
	mov	r14,r1
	add	#-56,r1
	mov.l	@(60,r2),r2
	mov.l	@(56,r1),r1
	add	r2,r1
	mov	r1,r0
	
	add	#8,r14
	mov	r14,r15
	mov.l	@r15+,r14
	rts	
	nop


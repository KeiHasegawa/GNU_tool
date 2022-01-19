	.section .text
	.align 1
	.global _f
_f:
	mov.w	r6,@-r7
	mov.w	r7,r6
	subs	#2,r7
	subs	#2,r7
	mov.w	r0,@(-2,r6)
	mov.w	r1,@(-4,r6)
	
	mov.w	@(-2,r6),r3
	mov.w	@(-4,r6),r2
	add.w	r3,r2
	mov.w	r2,r0
	
	adds	#2,r7
	adds	#2,r7
	mov.w	@r7+,r6
	rts

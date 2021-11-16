	.text
start:
	mov	#stack,sp
	jsr	_main
	nop
	jsr	@@0xcd		; simulator exit(0)

	.global _printf
_printf:
	jsr	@@0xce
	rts

	.global _puts
_puts:
	jsr	@@0xcf
	rts

	.global _putchar
_putchar:
	jsr	@@0xd0
	rts

	.global _memcpy
_memcpy:
	mov.w	r6,@-r7
	mov.w	r7,r6
	mov.w	#-6,r3
	add.w	r3,r7
	mov.w	r0,@(-2,r6)
	mov.w	r1,@(-4,r6)
	mov.w	r2,@(-6,r6)
	bra	.L5
.L6:
	mov.w	@(-4,r6),r3
	mov.w	r3,r2
	adds	#1,r2
	mov.w	r2,@(-4,r6)
	mov.w	@(-2,r6),r2
	mov.w	r2,r0
	adds	#1,r0
	mov.w	r0,@(-2,r6)
	mov.b	@r3,r3l
	mov.b	r3l,@r2
.L5:
	mov.w	@(-6,r6),r2
	mov.w	r2,r3
	subs	#1,r3
	mov.w	r3,@(-6,r6)
	mov.w	r2,r2
	bne	.L6
	nop
	mov.w	r2,r0
	mov.w	#6,r3
	add.w	r3,r7
	mov.w	@r7+,r6
	rts
	

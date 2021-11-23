	.text
start:
	ldc	#stack, sp
	jsr.a	_main
	nop
	.short	0x007f

	.global	_printf
_printf:
	.short	0x017f
	rts

	.global	_puts
_puts:
	.short	0x027f
	rts

	.global	_putchar
_putchar:
	.short	0x037f
	rts

	.global	_memcpy
_memcpy:
	enter	#8-2
	mov.w	r1,-4[fb]
	mov.w	r2,-6[fb]
	mov.w	-4[fb],r0
	mov.w	r0,-2[fb]
	jmp.a	.L13
.L14:
	mov.w	-6[fb],r2
	mov.w	r2,r0
	add.w	#1,r0
	mov.w	r0,-6[fb]
	mov.w	-4[fb],r0
	mov.w	r0,r1
	add.w	#1,r1
	mov.w	r1,-4[fb]
	mov.w	r2,a0
	mov.b	[a0],r1l
	mov.w	r0,a0
	mov.b	r1l,[a0]
.L13:
	mov.w	5[fb],r0
	mov.w	#-1,r2
	add.w	r0,r2
	mov.w	r2,5[fb]
	cmp.w	#0,r0
	jne	.L14
	mov.w	-2[fb],r0
	exitd

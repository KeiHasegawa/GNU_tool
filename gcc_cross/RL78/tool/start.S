r8	=	0xffef0
r10	=	0xffef2
r12	=	0xffef4

	.text
start:
	movw	sp, #stack
	call	!!%code(_main)
	nop
	.short	0x0631
	
	.global	_printf
_printf:
	.short	0x1631
	ret

	.global	_puts
_puts:
	.short	0x2631
	ret

	.global	_putchar
_putchar:
	.short	0x3631
	ret
	
	.global	_memcpy
_memcpy:
	; start of function
	; locals: 2 bytes
	subw	sp, #2
	movw	ax, [sp+6]
	movw	r8, ax
	movw	[sp], ax
	br	!!.L13
.L14:
	movw	ax, [sp+8]
	movw	r10, ax
	incw	ax
	movw	[sp+8], ax
	movw	ax, [sp+6]
	movw	r8, ax
	incw	ax
	movw	[sp+6], ax
	movw	ax, r10
	movw	r12, ax
	movw	hl, r12
	mov	a, [hl]
	mov	r10, a
	movw	ax, r8
	movw	r12, ax
	movw	bc, r12
	mov	a, r10
	mov	[bc], a
.L13:
	movw	ax, [sp+10]
	movw	r8, ax
	decw	ax
	movw	[sp+10], ax
	movw	ax, r8
	cmpw	ax, #0
	 skz
	 br	!!.L14
	movw	ax, [sp]
	movw	r8, ax
	addw	sp, #2
	ret
	

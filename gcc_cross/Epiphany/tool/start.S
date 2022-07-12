	.text
start:
	mov	r0, %low(_bss_start)
	movt	r0, %high(_bss_start)
	mov	r1, %low(_bss_end)
	movt	r1, %high(_bss_end)
	mov	r2, #0
.L1:
	sub	r3, r0, r1
	beq	.L2
	strb	r2, [r0]
	add	r0, r0, #1
	b	.L1
.L2:	
	mov	sp, %low(_stack)
	movt	sp, %high(_stack)
	mov	r2, %low(_main)
	movt	r2, %high(_main)
	jalr	r2
	.word	0xbacb

	.global	_printf
_printf:
	.word	0xbadb
	rts

	.global	_puts
_puts:
	.word	0xbaeb
	rts

	.global	_putchar
_putchar:
	.word	0xbafb
	rts

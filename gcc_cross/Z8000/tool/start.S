	.text
start:
	ld	r4, #_bss_start
	ld	r5, #_bss_end
	xor	r6, r6
.L1:
	cp	r4, r5
	jr	eq, .L2
	clrb	@r4
	inc	r4,#1
	jr	.L1
.L2:	
	ld	r15, #_stack
	call	_main
	.word	0x0c00
end:
	nop

	.global _printf
_printf:
	.word	0x0c01
	ret	t

	.global _puts
_puts:
	.word	0x0c02
	ret	t

	.global _putchar
_putchar:
	.word	0x0c03
	ret	t
	
	.global	_memcpy
_memcpy:
	push	@r15,r10 !CPG1
	ld	r10,r15
	dec	r15,#8
	ld	-2(r10),r7
	ld	-4(r10),r6
	ld	-6(r10),r5
	ld	r4,-2(r10)
	ld	-8(r10),r4
EL15:
	ld	r4,-6(r10)
	dec	r4,#1
	ld	-6(r10),r4
	cp	r4,#65535
	jr	eq,EL16
	ld	r1,r10
	dec	r1,#2
	ld	r5,@r1
	ld	r2,r10
	dec	r2,#4
	ld	r4,@r2
	ldb	rl3,@r4
	inc	r4,#1
	ld	@r2,r4
	ld	r4,r5
	ldb	@r4,rl3
	inc	r5,#1
	ld	@r1,r5
	jr	EL15
EL16:
	ld	r2,r4
	ld	r15,r10
	pop	r10,@r15
	ret	t

	.global	___main
___main:
	ret	t

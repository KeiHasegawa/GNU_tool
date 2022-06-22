	.text
start:
	mov	r0, @_bss_start
	mov	r1, @_bss_end
	mov	r2, 0
	.align	4	
.L1:
	cmp_s	r0, r1
	beq_s	@.L2	
	stb_s	r2, [r0]
	add_s	r0, r0, 1
	b_s	@.L1
	.align	4
.L2:	
	mov	gp, @__SDATA_BEGIN__
	mov	sp, @stack
	bl	@main
	.short	0xc7fc

	.align 4
	.global	printf
printf:
	.short	0xc7fd
	j_s	[blink]

	.align 4
	.global	puts
puts:
	.short	0xc7fe
	j_s	[blink]

	.align 4
	.global	putchar
putchar:
	.short	0xc7ff
	j_s	[blink]
	
	

	.text
start:
	// movl	r1 = _GLOBAL_OFFSET_TABLE_
	movl	r1 = _GLOBAL_OFFSET_TABLE_+8
	addl	r2 = @ltoffx(_bss_start#), r1
	addl	r3 = @ltoffx(_bss_end#), r1
.L1:
	cmp4.eq	p6, p7 = r2, r3
	(p6) br.cond.dptk .L2
	st1	[r2] = r0
	adds	r2 = 1, r2
	br	.L1
.L2:	
	addl	r12 = @ltoffx(stack#), r1
	ld8.mov	r12 = [r12], stack#
	br.call.sptk.many b0 = main#
	nop.m	0
	nop.i	0
	nop.i	0

	.global	printf
printf:
	br.ret.sptk.many b0

	.global	puts
puts:
	br.ret.sptk.many b0

	.global	putchar
putchar:
	br.ret.sptk.many b0
	

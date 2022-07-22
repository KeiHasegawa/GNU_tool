	.text
start:
	movl	r1 = _GLOBAL_OFFSET_TABLE_
	addl	r12 = @ltoffx(stack#), r1
	ld8.mov	r12 = [r12], stack#
	br.call.sptk.many b0 = main#
end:	
	nop.m	0
	nop.i	0
	nop.i	0


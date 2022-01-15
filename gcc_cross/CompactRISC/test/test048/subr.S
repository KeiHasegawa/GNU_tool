	.text
	.global	_f
_f:
	push	$2, r13, r14
	addd	$-8, (sp)
	movd	(sp), (r13)
	storw	r2, 0(r13)
	storw	r3, 2(r13)
	loadw	0(r13), r1
	loadw	2(r13), r0
	addw	r1, r0
	storw	r0, 4(r13)
	loadw	4(r13), r0
	movd	(r13), (sp)
	addd	$8, (sp)
	popret	$2, r13, r14
	

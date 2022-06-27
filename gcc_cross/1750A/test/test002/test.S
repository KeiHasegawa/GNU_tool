	.text
start:
	li	r15, stack
	js	r13, main
	.word	0xcccb
	
	.global  f
f:
	pshm	r13, r14
	sisp	r15, 4
	lr	r14, r15
	st	r0, 0, r14
	st	r1, 2, r14
	l	r0, 0, r14
	a	r0, 2, r14
	lr	r15, r14
	aisp	r15, 4
	popm	r14, r14
	urs	r15
	
	.global	main
main:
	pshm	r13, r14
	lr	r14, r15
	li	r0, 5
	li	r1, 6
	js	r13, f
	lr	r15, r14
	popm	r14, r14
	urs	r15

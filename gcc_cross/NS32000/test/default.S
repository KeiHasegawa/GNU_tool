	.text
start:
	addr	_stack(pc), r0
	lprd	sp, r0
	bsr	_main
	nop

	.global	___main
___main:
	ret	0

	.text
start:
	addr	_stack(pc), r0
	lprd	sp, r0
	bsr	func
	nop

func:
	ret	0

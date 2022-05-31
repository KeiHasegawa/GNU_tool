	.text
start:
	addr	stack(pc), r0
	lprd	sp, r0
	bsr	func
	nop

func:
	ret	0

	.sect .softregs
	.globl _.frame
_.frame:
	.space	2

	.text
	.global start
start:
	ldx	#stack
	txs
	bsr	func
	nop
	nop
end:
	nop

func:
	rts
	

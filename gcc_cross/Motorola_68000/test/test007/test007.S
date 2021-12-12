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
	

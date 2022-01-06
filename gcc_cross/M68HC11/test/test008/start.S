	.text
	.global start
start:
	ldx	#stack
	txs
	bsr	main
end:
	nop


func:
	rts
	

	.section .softregs
	.global _.frame
_.frame:
	.space 2
	
	.text
	.global start
start:
	ldx	#stack
	txs
	bsr	main
	nop

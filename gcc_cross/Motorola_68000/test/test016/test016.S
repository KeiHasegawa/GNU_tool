	.text
	.global start
start:
	ldx	#stack
	txs
	bsr	main
	nop
	nop
	.word	0xcd00

main:
	rts
	

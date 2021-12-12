	.section .softregs
	.global _.frame
_.frame:
	.space 2
	
	.text
start:
	ldx	#stack
	txs
	bsr	main
end:
	nop


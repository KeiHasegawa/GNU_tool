	.section .softregs
_.frame:
	.space 2
	
	.text
start:
	nop
	nop
	ldx	#stack
	txs
	bsr	main
end:
	nop
	nop
	nop
	
	.mode mlong
	.sect	.text
	.globl	main
main:
	ldx	*_.frame
	pshx
	sts	*_.frame
	clra
	clrb
	ldx	#0
	puly
	sty	*_.frame
	rts
	

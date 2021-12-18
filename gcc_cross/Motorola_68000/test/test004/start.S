	.text
	.global start
start:
	ldd	#_bss_start
.L1:
	cpd	#_bss_end
	beq	.L2
	xgdx
	clr	0,x
	xgdx
	addd	#1
	bra	.L1
.L2:
	ldx	#stack
	txs
	bsr	main


_exit:	
	bra	.


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
	ldx	#_stack
	txs
	bsr	main
	.word	0xcd00


	.global printf
printf:
	.word	0xcd05
	rts

	.global puts
puts:
	.word	0xcd07
	rts

	.global putchar
putchar:
	.word	0xcd09
	rts
	

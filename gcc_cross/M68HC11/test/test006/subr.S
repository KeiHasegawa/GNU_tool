	.mode mlong
	.sect	.text
	.globl	f
	.type	f,@function
f:
	ldy	*_.frame
	pshy
	pshx
	pshx
	sts	*_.frame
	ldy	*_.frame
	std	3,y
	stx	1,y
	ldy	*_.frame
	ldd	3,y
	ldx	1,y
	addd	11,y
	xgdx
	adcb	10,y
	adca	9,y
	xgdx
	puly
	puly
	puly
	sty	*_.frame
	rts

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
	ldy	*_.d1
	pshy
	ldy	*_.d2
	pshy
	ldy	*_.frame
	std	3,y
	stx	1,y
	ldy	*_.frame
	ldd	3,y
	std	*_.d2
	ldd	1,y
	std	*_.d1
	ldd	*_.d2
	ldx	*_.d1
	ldy	*_.frame
	subd	11,y
	xgdx
	sbcb	10,y
	sbca	9,y
	xgdx
	puly
	sty	*_.d2
	puly
	sty	*_.d1
	puly
	puly
	puly
	sty	*_.frame
	rts



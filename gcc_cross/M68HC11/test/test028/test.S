	.file	"a.c"
	.text
	.globl	f
	.type	f, @function
f:
	ldy	*_.frame
	pshy
	pshy
	pshy
	pshy
	pshy
	sts	*_.frame
	ldy	*_.frame
	stx	1, y
	std	3, y
	ldy	*_.frame
	ldx	1, y
	eora	#128
	eorb	#0
	xgdx
	eora	#255
	eorb	#255
	xgdx
	ldy	*_.frame
	stx	5, y
	ldy	*_.frame
	ldx	3, y
	ldd	5, y
	ldy	*_.frame
	stx	7, y
	std	9, y
	ldy	*_.frame
	ldx	5, y
	ldd	7, y
	puly
	puly
	puly
	puly
	puly
	sty	*_.frame
	rts
	.size	f, .-f
	.globl	__extendsfdf2
	.section	.rodata
.LC0:
	.string	"hello world %f\n"
	.text
	.globl	main
	.type	main, @function
main:
	ldy	*_.frame
	pshy
	tsy
	xgdy
	addd	#-16
	xgdy
	tys
	sts	*_.frame
	ldd	#16544
	xgdx
	ldd	#0
	bsr	f
	xgdy
	pshy
	pshx
	ldd	*_.frame
	addd	#1
	bsr	__extendsfdf2
	tsy
	xgdy
	addd	#4
	xgdy
	tys
	ldy	*_.frame
	ldx	1, y
	ldd	3, y
	ldy	*_.frame
	stx	9, y
	std	11, y
	ldy	*_.frame
	ldx	5, y
	ldd	7, y
	ldy	*_.frame
	stx	13, y
	std	15, y
	ldy	*_.frame
	ldx	13, y
	ldd	15, y
	xgdy
	pshy
	pshx
	ldy	*_.frame
	ldx	9, y
	ldd	11, y
	xgdy
	pshy
	pshx
	ldd	#.LC0
	bsr	printf
	tsy
	xgdy
	addd	#8
	xgdy
	tys
	ldx	#0
	clra
	clrb
	tsy
	xgdy
	addd	#16
	xgdy
	tys
	puly
	sty	*_.frame
	rts
	.size	main, .-main
	.ident	"GCC: (GNU) 10.2.0"

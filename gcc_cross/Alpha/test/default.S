	.text
start:
	lda	$29, 33864($29)	   # set $29(gp)
	ldah	$30, 0($31)
	lda	$30, 0x1000($30)   # set $30(sp)
#	lda	$30, stack
	jsr	$26, main
	nop
	nop
end:
	nop

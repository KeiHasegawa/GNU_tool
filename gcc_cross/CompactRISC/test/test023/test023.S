	.text
start:
	movd	$label@l, (r3,r2)
	addd	$label@l, (r3,r2)
	cmpd	$label@l, (r3,r2)
	movd	$label2@l, (r3,r2)
	addd	$label2@l, (r3,r2)
	cmpd	$label2@l, (r3,r2)
	nop
end:
	nop

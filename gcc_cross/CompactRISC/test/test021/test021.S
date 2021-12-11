	.text
start:
	movw	$1, r0
	movw	$2, r1	
	cmpw	r0, r1
	beq	label
	nop
	nop
end:
	nop

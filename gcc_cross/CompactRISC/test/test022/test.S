	.text
start:
	movw	$1, r0
	movw	$1, r1
	cmpw	r0, r1
	bne	label
	nop
	blt	label
	nop
	bgt	label
	nop
	movw	$2, r0
	movw	$1, r1	
	cmpw	r0, r1
	beq	label
	nop
	ble	label
	nop
	movw	$1, r0
	movw	$2, r1	
	cmpw	r0, r1
	bge	label	
	nop
	movw	$1, r0
	movw	$1, r1
	cmpw	r0, r1
	bne	label2
	nop
	blt	label2
	nop
	bgt	label2
	nop
	movw	$2, r0
	movw	$1, r1	
	cmpw	r0, r1
	beq	label2
	nop
	ble	label2
	nop
	movw	$1, r0
	movw	$2, r1	
	cmpw	r0, r1
	bge	label2	
	nop
	movw	$1, r0
	movw	$1, r1
	cmpw	r0, r1
	bne	label3
	nop
	blt	label3
	nop
	bgt	label3
	nop
	movw	$2, r0
	movw	$1, r1	
	cmpw	r0, r1
	beq	label3
	nop
	ble	label3
	nop
	movw	$1, r0
	movw	$2, r1	
	cmpw	r0, r1
	bge	label3	
	nop
end:
	nop

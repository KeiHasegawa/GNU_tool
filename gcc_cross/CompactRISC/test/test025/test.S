	.text
start:	
	movd $label1, (r1,r0)
	movd $label2, (r1,r0)
	movd $label3, (r1,r0)
	movd $label4, (r3,r2)
	movd $label5, (r3,r2)
	movd $label6, (r3,r2)
	addd $label1, (r3,r2)
	addd $label2, (r3,r2)
	addd $label3, (r3,r2)
	addd $label4, (r3,r2)
	addd $label5, (r3,r2)
	addd $label6, (r3,r2)
	cmpd $label1, (r5,r4)
	cmpd $label2, (r5,r4)
	cmpd $label3, (r5,r4)
	cmpd $label4, (r5,r4)
	cmpd $label5, (r5,r4)
	cmpd $label6, (r5,r4)
	movw	$1, r2
	movw	$2, r3
	cmpw	r2, r3
	beq label10
	beq label11
	beq label12
	nop
end:
	nop
	

	.section	.text
	.align 4
	.global	f
f:
	l.addi	r1, r1, -16
	l.sw	8(r1), r2
	l.addi	r2, r1, 16
	l.sw	12(r1), r9
	l.sw	-12(r2), r3
	l.sw	-16(r2), r4
	
	l.lwz	r19, -12(r2)
	l.lwz	r17, -16(r2)
	l.add	r17, r19, r17
	l.or	r11, r17, r17
	
	l.lwz	r2, 8(r1)
	l.lwz	r9, 12(r1)
	l.addi	r1, r1, 16
	l.jr	r9
	l.nop

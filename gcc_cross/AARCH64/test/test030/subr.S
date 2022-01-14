	.arch armv8-a
	.text
	.align	2
	.global	f
f:
	stp	x29, x30, [sp, -24]!
	mov	x29, sp
	
	str	w0, [x29, 16]
	str	w1, [x29, 20]
	ldr	w1, [x29, 20]
	ldr	w0, [x29, 16]
	add	w0, w1, w0
	
	ldp	x29, x30, [sp], 24
	ret

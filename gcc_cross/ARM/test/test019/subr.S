	.text
	.align	2
	.global	f
	.arch armv4t
	.syntax unified
	.arm
	.fpu softvfp
	.type	f, %function
f:
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r0, r3
	
	sub	sp, fp, #4
	pop	{fp, pc}

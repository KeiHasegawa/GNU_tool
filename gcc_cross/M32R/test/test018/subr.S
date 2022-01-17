	.section .text
	.balign 4
	.global	f
f:
	push fp
	addi sp,#-8
	mv fp,sp
	
	st r0,@(fp)
	st r1,@(4,fp)
	ld r5,@(fp)
	ld r4,@(4,fp)
	add r4,r5
	mv r0,r4
	
	addi sp,#8
	pop fp
	jmp lr

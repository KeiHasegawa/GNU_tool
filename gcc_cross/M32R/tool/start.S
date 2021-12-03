	.text
start:
	ld24	r4, #_bss_start
	ld24	r5, #_bss_end
	ldi	r6, #0
.L1:
	beq	r4, r5, .L2
	nop
	stb	r6,@(r4)
	add3	r4, r4, #1
	bra	.L1
	nop
.L2:
	ld24 sp,#_stack
	bl main
	nop
	nop
	.word 0xbadbeef0
	
	.global printf
printf:
	jmp lr
	nop
	
	.global puts
puts:
	jmp lr
	nop
	
	.global putchar
putchar:
	jmp lr
	nop
	
	.global	memcpy
memcpy:
	; PROLOGUE, vars= 16, regs= 1, args= 0, extra= 0
	push fp
	addi sp,#-16
	mv fp,sp
	st r0,@(4,fp)
	st r1,@(8,fp)
	st r2,@(12,fp)
	ld r4,@(4,fp)
	st r4,@(fp)
	bra .L13
	.balign 4
.L14:
	ld r5,@(8,fp)
	add3 r4,r5,#1
	st r4,@(8,fp)
	ld r4,@(4,fp)
	add3 r6,r4,#1
	st r6,@(4,fp)
	ldb r5,@(r5)
	stb r5,@(r4)
	.balign 4
.L13:
	ld r4,@(12,fp)
	add3 r5,r4,#-1
	st r5,@(12,fp)
	bnez r4,.L14
	ld r4,@(fp)
	mv r0,r4
	addi sp,#16
	pop fp
	jmp lr

	.text
start:
	nop
	movhi hi(stack),r0,sp
	movea lo(stack),sp,sp
	movhi hi(_main),r0,r10
	movea lo(_main),r10,r10
	jarl .+4, r31 ; add 4, r31 ; jmp r10
end:
	nop

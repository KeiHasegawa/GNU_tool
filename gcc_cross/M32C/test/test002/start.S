	.text
start:
	mov.w	#_bss_start, r0
	mov.w	#_bss_end, r1
	mov.w	#0, r2
.L1:	
	cmp.w	r0, r1
	jeq	.L2
	mov.w	r0,a0
	mov.b	#0,[a0]
	add.w	#1,r0
	jmp.a	.L1
.L2:
	ldc	#_stack, sp
	jsr.a	_main
	nop

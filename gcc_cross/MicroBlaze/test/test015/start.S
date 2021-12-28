	.text
	.global _start
start:
	nop
	la	r1, r0, _stack-16

      	brlid	r15, main
	nop
	brki	r14, 96
	nop

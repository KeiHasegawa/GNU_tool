	.text
	mov	stack, a0
	mov	a0, sp
start:
	nop
	nop
	call func,[],0
	nop

func:
	ret [a3],4
	

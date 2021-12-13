	.text
	mov	stack, a0
	mov	a0, sp
start:
	call func,[],0
	nop
	nop
	nop

func:
	movm [a3],(sp)
	ret [a3],4



	
	

	.text
	mov	stack, a0
	mov	a0, sp
start:
	nop
	nop
	call _main,[],0
	nop
	break

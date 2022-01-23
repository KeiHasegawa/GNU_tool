	.text
start:
	nop
	mov.l	label1,r15
	mov.l	label2,r1
	jsr	@r1
	nop
	trapa	#0xc3
	nop

	.align 2
label1:
	.long	stack
label2:
	.long	_main
	
	

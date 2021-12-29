	.text
start:
	nop
	ldr	sp, label
	bl	main
	nop

	.align	2
label:
	.word	stack
	

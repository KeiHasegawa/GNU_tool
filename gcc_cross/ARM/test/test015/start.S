	.text
start:
	nop
	ldr	sp, label
	bl	main
	nop
	.word 0xe7ffdefe
	nop

	.align	2
label:
	.word	stack
	

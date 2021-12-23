	.text
start:
	nop
	ldr	sp, label
	bl	main
	nop
	.word 0xe7ffdefe

	.align	2
label:
	.word	stack
	

	.text
start:
	lis 1,stack@ha
	la 1,stack@l(1)
	bl main
	nop	
	twge 2, 2
	nop	

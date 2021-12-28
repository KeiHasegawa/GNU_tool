	.text
start:
	lis 1,stack@ha
	la 1,stack@l(1)
	bl main
	nop	

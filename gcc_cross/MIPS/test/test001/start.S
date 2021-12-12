	.text
start:
	nop
	la	$gp, _gp
	la	$sp, _stack
	jal	main
	nop
my_end:
	nop
	

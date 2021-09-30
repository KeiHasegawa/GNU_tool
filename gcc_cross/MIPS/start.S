	.text
start:
	nop
	la	$gp, _gp
	la	$sp, stack
	jal	main
	nop
my_end:
	nop
	

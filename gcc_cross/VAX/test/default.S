	.text
start:
	movl	$stack, %sp
	calls	$2, main
	nop
end:
	nop
	

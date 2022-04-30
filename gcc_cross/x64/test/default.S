	.text
start:
	movq	$stack, %rsp
	callq	main
end:	
	nop

	

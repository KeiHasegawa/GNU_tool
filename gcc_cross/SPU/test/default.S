	.text
start:
	ila	$sp, stack-32
	brsl	$lr, main
end:
	nop
	

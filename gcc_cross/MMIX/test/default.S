	.text
start:
	PUT	rG, #32
	GETA	$254, stack
	PUSHJ	$1, main
	add	$0, $0, 0	
end:	
	add	$0, $0, 0

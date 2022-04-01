	.text
start:
	PUT	rG, #fd
	GETA	$254, stack
	PUSHJ	$1, main
	add	$0, $0, 0	
end:	
	add	$0, $0, 0

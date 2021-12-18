	.text
start:
	la	$2, _bss_start
	la	$3, _bss_end
$L1:
	beq	$2, $3, $L2
	sb	$0, 0($2)
	addiu	$2, $2, 1
	b	$L1
$L2:	
	nop
	la	$gp, _gp
	la	$sp, _stack
	jal	main
	nop
_exit:
	b	.
	
	

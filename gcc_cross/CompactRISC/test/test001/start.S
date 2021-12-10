	.text
start:
	movw	$_stack,sp
	bal (ra), _main@c
	nop
end:
	nop

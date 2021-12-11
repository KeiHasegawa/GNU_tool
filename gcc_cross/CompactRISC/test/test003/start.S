	.text
start:
	movw	$stack,sp
	bal (ra), _main@c
	nop
end:
	nop

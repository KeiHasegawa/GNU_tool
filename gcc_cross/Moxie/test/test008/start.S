	.text
start:
	nop
	ldi.l	$sp, stack
	jsra	main
	nop

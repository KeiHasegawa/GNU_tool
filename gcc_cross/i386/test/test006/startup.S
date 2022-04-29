	.text
	.global	startup
startup:
	mov	$stack, %esp
	call	main
	nop

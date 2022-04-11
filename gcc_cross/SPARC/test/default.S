	.text
start:
	sethi	%hi(stack-64), %sp
	or	%sp, %lo(stack-64), %sp
	call	main
	nop
end:	
	nop

	

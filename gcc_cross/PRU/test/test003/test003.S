	.text
start:
	nop
	ldi32	sp, stack
	call	%label(my_func)
	nop
	
my_func:
	ret

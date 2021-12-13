	.text
start:
	nop
	ldi32	sp, stack
	call	%label(my_func)
end:
	nop
	
my_func:
	ret

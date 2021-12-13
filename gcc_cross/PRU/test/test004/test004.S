	.text
start:
	ldi32	sp, stack
	call	%label(func)
end:
	nop
	
func:
	ret

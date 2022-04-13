	.text
start:
	sethi	%hi(TRAP_BASE), %o0
	or	%o0, %lo(TRAP_BASE), %o0
	wr	%o0, %tbr

	wr	2, %wim

	sethi	%hi(stack-96), %sp
	or	%sp, %lo(stack-96), %sp
	
	call	main
	nop
end:	
	nop

	

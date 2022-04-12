	.text
start:
	sethi	%hi(TRAP_BASE), %o0
	or	%o0, %lo(TRAP_BASE), %o0
	wr	%o0, %tbr

	wr	0xff, %wim

	sethi	%hi(stack), %sp
	or	%sp, %lo(stack), %sp
	
	call	main
	nop
end:	
	nop

	

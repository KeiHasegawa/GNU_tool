	.text
start:
	l.nop
	l.nop
	l.movhi	r1, ha(stack)
	l.addi	r1, r1, lo(stack)
	l.jal	main
	l.nop
	l.nop
	l.nop
end:
	l.nop
	

func:
	l.jr	r9
	l.nop
	

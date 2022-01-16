	.text
	.global f
f:
	addi sp,#-24,sp
	sti fp, @(sp,8)
	addi sp,#8,fp
	movsg lr, gr5
	sti gr5, @(fp,8)
	
	sti gr8, @(fp,-4)
	sti gr9, @(fp,-8)
	ldi @(fp,-4), gr5
	ldi @(fp,-8), gr4
	add gr5,gr4,gr4
	mov gr4, gr8
	
	ldi @(fp,8), gr5
	ld @(fp,gr0), fp
	addi sp,#24,sp
	jmpl @(gr5,gr0)
	

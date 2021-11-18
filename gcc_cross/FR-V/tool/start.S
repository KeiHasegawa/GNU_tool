	.global _start
_start:
	sethi	#hi(_stack), sp
	setlo	#lo(_stack), sp
	sethi	#hi(gp), gr16
	setlo	#lo(gp), gr16
	call	main
	nop
	.word	0x0badbeef

	.global __main
__main:
	ret
	
	.global printf
printf:
	.word	0x1badbeef
	ret

	.global puts
puts:
	.word	0x2badbeef
	ret

	.global putchar
putchar:
	.word	0x3badbeef
	ret

	.globl memcpy
memcpy:
	addi sp,#-40,sp
	sti fp, @(sp,24)
	addi sp,#24,fp
	movsg lr, gr5
	sti gr5, @(fp,8)
	sti gr8, @(fp,-12)
	sti gr9, @(fp,-16)
	sti gr10, @(fp,-20)
	ldi @(fp,-12), gr4
	sti gr4, @(fp,-4)
	bra .L14
.L15:
	ldi @(fp,-16), gr5
	addi gr5,#1,gr4
	sti gr4, @(fp,-16)
	ldi @(fp,-12), gr4
	addi gr4,#1,gr6
	sti gr6, @(fp,-12)
	ldsb @(gr5,gr0),gr5
	stb gr5, @(gr4,gr0)
.L14:
	ldi @(fp,-20), gr4
	addi gr4,#-1,gr5
	sti gr5, @(fp,-20)
	cmpi gr4, #0, icc0
	bne icc0,2,.L15
	ldi @(fp,-4), gr4
	mov gr4, gr8
	ldi @(fp,8), gr5
	ld @(fp,gr0), fp
	addi sp,#40,sp
	jmpl @(gr5,gr0)
	

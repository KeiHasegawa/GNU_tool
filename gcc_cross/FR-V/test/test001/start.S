	.global _start
_start:
	sethi	#hi(_bss_start), gr4
	setlo	#lo(_bss_start), gr4
	sethi	#hi(_bss_end), gr5
	setlo	#lo(_bss_end), gr5
.L1:	
	cmp	gr4,gr5,icc0
	beq	icc0,2,.L2
	stb	gr0, @(gr4,gr0)
	addi	gr4,#1,gr4
	bra	.L1
.L2:	

	sethi	#hi(_sbss_start), gr4
	setlo	#lo(_sbss_start), gr4
	sethi	#hi(_sbss_end), gr5
	setlo	#lo(_sbss_end), gr5
.L3:	
	cmp	gr4,gr5,icc0
	beq	icc0,2,.L4
	stb	gr0, @(gr4,gr0)
	addi	gr4,#1,gr4
	bra	.L3
.L4:	

	sethi	#hi(_stack), sp
	setlo	#lo(_stack), sp
	sethi	#hi(_gp), gr16
	setlo	#lo(_gp), gr16
	call	main
	nop

_exit:
	bra	.

	.global __main
__main:
	ret

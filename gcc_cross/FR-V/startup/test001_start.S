	.global _start
_start:
	sethi	#hi(_stack), sp
	setlo	#lo(_stack), sp
	sethi	#hi(gp), gr16
	setlo	#lo(gp), gr16
	call	main
	nop
end:
	nop

	.global __main
__main:
	ret
	
	

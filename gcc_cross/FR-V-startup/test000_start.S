	.global _start
_start:
	sethi	#hi(_stack), sp
	setlo	#lo(_stack), sp
	mov	sp, fp
	call	main
	nop
end:
	nop

	.global __main
__main:
	ret
	
	

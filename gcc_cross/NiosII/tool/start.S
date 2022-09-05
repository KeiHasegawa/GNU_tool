	.text
start:
	movhi	r1, %hiadj(_bss_start)
	addi	r1, r1, %lo(_bss_start)
	movhi	r2, %hiadj(_bss_end)
	addi	r2, r2, %lo(_bss_end)
.L1:
	beq	r1, r2, .L2
	stb	r0, 0(r1)
	addi	r1, r1, 1
	br	.L1
.L2:	
	movhi	sp, %hiadj(stack)
	addi	sp, sp, %lo(stack)
	movhi	gp, %hiadj(_gp)
	addi	gp, gp, %lo(_gp)
	call	main
	.long	0x1000003d

	.global	printf
printf:
	.long	0x2000003d
	ret

	.global	puts
puts:
	.long	0x3000003d	
	ret

	.global	putchar
putchar:
	.long	0x4000003d	
	ret

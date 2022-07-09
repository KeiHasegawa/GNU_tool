	.text
start:
	lui	a0, %hi(_bss_start)
	addi	a0, a0, %lo(_bss_start)
	lui	a1, %hi(_bss_end)
	addi	a1, a1, %lo(_bss_end)
	li	a2, 0
.L1:
	beq	a0, a1, .L2
	sb	a2, 0(a0)
	addi	a0, a0, 1
	j	.L1
.L2:	
	lui	sp, %hi(stack)
	addi	sp, sp, %lo(stack)
	call	main
	.word	0xbadbeef0

	.global	printf
printf:
	.word	0xbadbeef1
	jr	ra

	.global	puts
puts:
	.word	0xbadbeef2
	jr	ra
	
	.global	putchar
putchar:
	.word	0xbadbeef4
	jr	ra

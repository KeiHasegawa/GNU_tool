	.text
start:
	lda	$29, 0x8000($31)
	lda	$29, 0x100($29)

	lda	$0, _bss_start
	lda	$1, _bss_end
.L1:
	cmpeq	$0, $1, $2
	bne	$2, .L2
	stb	$31, 0($0)
	lda	$0, 1($0)
	br	$31, .L1
.L2:	
	lda	$30, stack
	jsr	$26, main
	halt
	
	.global	printf
printf:
	.long	0x0badbeef
	ret

	.global	puts
puts:
	.long	0x1badbeef
	ret

	.global	putchar
putchar:
	.long	0x5badbeef
	ret

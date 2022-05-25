	.text
start:
	lda	$29, 36232($29)	   # set $29(gp)
	ldah	$30, 0($31)
	lda	$30, 0x2000($30)   # set $30(sp)
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

	.text
start:
	ila	$3, _bss_start
	ila	$4, _bss_end
	il	$5, 0
.L1:
	ceq	$6, $3, $4
	brnz	$6, .L2
	cbd	$6, 0($3)
	shufb	$3, $5, $3, $6
	stqd	$5, 0($3)
	ai	$3, $3, 1
	br	.L1
.L2:	
	ila	$sp, stack-2048
	brsl	$lr, main
	.long	0x800081

	.global	printf
printf:
	.long	0x800083
	bi	$lr
	
	.global	puts
puts:
	.long	0x800085
	bi	$lr

	.global	putchar
putchar:
	.long	0x800087
	bi	$lr


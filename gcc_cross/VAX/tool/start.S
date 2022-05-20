	.text
start:
	movl	$_bss_start, %r0
	movl	$_bss_end, %r1
.L1:	
	cmpl	%r0, %r1
	jeql	.L2
	clrb	(%r0)
	addl3	%r0, $1, %r0
	jbr	.L1
.L2:	
	movl	$stack, %sp
	calls	$2, main
	halt

	.global	printf
printf:
	.word 0
       	.word 0x5959
	ret

	.global	puts
puts:
	.word 0
       	.word 0x595a
	ret

	.global	putchar
putchar:
	.word 0
       	.word 0x595b
	ret
	


	.text
start:
	movl	$_bss_start, %eax
	movl	$_bss_end, %edx
.L1:
	cmpl	%eax, %edx
	je	.L2
	movb	$0, (%eax)
	add	$1, %eax
	jmp	.L1
.L2:	
	finit
	movl	$stack, %esp
	call	main
	.word	0x040f

	.global	printf
printf:
	.word	0x250f
	ret

	.global	puts
puts:
	.word	0x270f
	ret

	.global	putchar
putchar:
	.word	0x360f
	ret
	

	

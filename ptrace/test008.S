	.text
	.global	main
main:
	movl	$0, %eax
	movl	%eax, %dr7
	movl	$0x804a6a0, %eax
	movl	%eax, %dr0
	movl	0xd0101, %eax
	movl	%eax, %dr7
	movl	$0, %eax
	movl	%eax, %dr6
	ret

	.text
	.code16
	.global	start16
start16:
	mov	%cr0, %eax
	or	$1, %al
	mov	%eax, %cr0
	lgdt	my_gdt
	mov	$0x18, %ax
	mov	%ax, %ss	
	ljmpl	$0x10, $start32

	.data
my_gdt:
	.word	0x30
	.long	my_gdt_data

my_gdt_data:
	.long	0,	0
	.long	0,	0
	.long	0xffff, 0xcf9b00 # 32 bit flat code segment (0x10)
	.long	0xffff, 0xcf9300 # 32 bit flat data segment (0x18)
	.long	0xffff, 0xaf9b00 # 64 bit flat code segment (0x20)
	.long	0xffff, 0xaf9300 # 64 bit flat data segment (0x28)

	.text
	.code32
start32:
	# IA32_EFER.LME = 1
	mov	$0xc0000080, %ecx
	rdmsr
	or	$0x100, %eax
	wrmsr

	# CR4.PAE = 1
	mov	%cr4, %eax
	or	$0x20, %eax
	mov	%eax, %cr4

	# CR0.PG = 1
	mov	%cr0, %eax
	mov	$0x80000000, %ebx
	or	%ebx, %eax
	mov	%eax, %cr0

	movw	$0x28, %ax
	movw	%ax, %ss
	ljmpl	$0x20, $start64

	.code64	
start64:	
	mov	$_bss_start, %rax
	mov	$_bss_end, %rdx
.L1:
	cmp	%rax, %rdx
	je	.L2
	movb	$0, (%rax)
	add	$1, %rax
	jmp	.L1
.L2:	
	finit
	mov	$stack, %rsp
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


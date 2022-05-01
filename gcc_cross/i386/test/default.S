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
	mov	%ax, %ds
	mov	%ax, %es
	ljmpl	$0x10, $start32

	.data
my_gdt:
	.word	0x20
	.long	my_gdt_data

my_gdt_data:
	.long	0,	0
	.long	0,	0
	.long	0xffff, 0xcf9b00 # 32 bit flat code segment (0x10)
	.long	0xffff, 0xcf9300 # 32 bit flat data segment (0x18)

	.text
	.code32
start32:
	movl	$stack, %esp
	call	main
	nop

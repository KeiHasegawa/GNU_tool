	.text
	.code16
	.global	my_routine
my_routine:
	mov	%cr0, %eax
	or	$1, %al
	mov	%eax, %cr0
	lgdt	my_gdt
	mov	$0x18, %ax
	mov	%ax, %ss	
	ljmpl	$0x10, $startup

	.data
my_gdt:
	.word	0x30
	.long	my_gdt_data

my_gdt_data:
	.long	0,	0
	.long	0,	0
	.long	0xffff, 0xcf9b00 # 32 bit flat code segment (0x10)
	.long	0xffff, 0xcf9300 # 32 bit flat data segment (0x18)
	.long	0xffff, 0x9b0f	 # 16 bit code segment base=0xf0000 limit=0xffff
	.long	0xffff, 0x9300   # 16 bit data segment base=0x0 limit=0xffff


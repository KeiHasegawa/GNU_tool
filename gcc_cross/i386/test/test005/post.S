	.text
	.code16
	.global	post
post:
	xor	%ax, %ax
	
	# first reset the DMA controllers
	out	%al, $PORT_DMA1_MASTER_CLEAR
	out	%al, $PORT_DMA2_MASTER_CLEAR

	# then initialize the DMA controllers
	mov	$0xc0, %al
	out	%al, $PORT_DMA2_MODE_REG  # cascade mode of channel 4 enabled
	mov	$0x00, %al 
	out	%al, $PORT_DMA2_MASK_REG  # unmask channel 4

	# Examine CMOS shutdown status.
	mov	$0x0f, %al
	out	%al, $PORT_CMOS_INDEX
	in	$PORT_CMOS_DATA, %al
	
	# backup status
	mov %al, %bl

	# Reset CMOS shutdown status.
	mov	$0x0f, %al
	out	%al, $PORT_CMOS_INDEX  # select CMOS register 0xf
	mov	$0x00, %al
	out	%al, $PORT_CMOS_DATA   # set shutdown action to normal

	# Examine CMOS shutdown status.
	mov	%bl, %al

	# 0x00, 0x0D+ = normal startup
	cmp	$0x00, %al
	jz	normal_post
	cmp	$0x0d, %al
	jae	normal_post

	# 0x05 = eoi + jmp via [0x40:0x67] jump
	int3
/*
	cmp	$0x05, %al
	je	eoi_jmp_post
*/	
	
normal_post:
	# case 0: normal startup
	cli
	mov	$stack, %ax
	mov	%ax, %sp
	xor	%ax, %ax
	mov	%ax, %ds
	mov	%ax, %ss

	# Save shutdown status
	mov	%bl, power_down_status

	cmp	$0xfe, %bl
	jz	s3_post
	
	# clear BIOS data area
	mov	%ax, %es
	mov	$bios_data_size, %cx
	sar	%cx
	mov	$bios_data, %di 
	cld
	rep	stosw

	call	post_init_ivt

	int3
	nop

s3_post:
	nop
	int3
	nop
	

	.text
	.global post_init_ivt
post_init_ivt:
	# set first 120 interrupts to default handler
	xor	%di, %di   # offset index
	mov	$120, %cx  # counter (120 interrupts)
	mov	$0xf000, %ax
	shl	$16, %eax
	mov	$dummy_iret_handler, %ax
	cld
	rep	stos %eax,%es:(%edi)

	# Master PIC vector
	mov	$0x0020, %bx
	mov	$0x08, %cl
	mov	$dummy_master_pic_irq_handler, %ax
.L1:
	mov	%ax, (%bx)
	add	$4, %bx
	loop	.L1

	# Slave PIC vector
	add	$0x0180, %bx
	mov	$0x08, %cl
	mov	$dummy_slave_pic_irq_handler, %ax
.L2:
	mov	%ax, (%bx)
	add	$4, %bx
	loop	.L2

	int3

	# Printer Services vector
	# SET_INT_VECTOR(0x17, #0xF000, #int17_handler)
	nop
	
	int3

	ret

dummy_master_pic_irq_handler:
	push	%ax
	call	eoi_master_pic
	pop	%ax
	iret

dummy_slave_pic_irq_handler:
	push	%ax
	call	eoi_both_pics
	pop	%ax
	iret
	
eoi_both_pics:
	mov	$0x20, %al
	out	%al, $PORT_PIC2_CMD # slave  PIC EOI
eoi_master_pic:
	mov	$0x20, %al
	out	%al, $PORT_PIC1_CMD  # master PIC EOI
	ret

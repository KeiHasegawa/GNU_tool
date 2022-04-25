	.text
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
	mov	$0xfffe, %ax
	mov	%ax, %sp
	xor	%ax, %ax
	mov	%ax, %ds
	mov	%ax, %ss
	int3
	nop
	

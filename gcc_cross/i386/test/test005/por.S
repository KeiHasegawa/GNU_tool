	.text
	.org 0xe05b-1
post:
	xor %ax, %ax

	.org 0xfff0-1
	.global	power_on_reset
power_on_reset:
	jmp	post
	nop


	

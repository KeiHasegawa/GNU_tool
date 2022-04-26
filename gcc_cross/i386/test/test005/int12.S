	.text
	.code16
	.global	int12_handler
int12_handler:
	push	%ds
	mov	$0x0040, %ax
	mov	%ax, %ds
	mov	0x0013,  %ax
	pop	%ds
	iret

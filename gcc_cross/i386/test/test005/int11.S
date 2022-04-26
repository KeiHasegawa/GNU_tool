	.text
	.code16
	.global	int11_handler
int11_handler:
	push	%ds
	mov	$0x0040, %ax
	mov	%ax, %ds
	mov	0x0010, %ax
	pop	%ds
	iret

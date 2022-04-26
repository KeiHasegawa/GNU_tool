	.text
	.code16
	.global	int17_handler
int17_handler:
	push	%ds
	pusha
	xor	%ax, %ax
	mov	%ax, %ds
	call	int17_function
	popa
	pop	%ds
	iret

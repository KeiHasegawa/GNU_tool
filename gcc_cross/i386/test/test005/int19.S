	.text
	.code16
	.global	int19_handler
int19_handler:
	jmp	int19_relocated


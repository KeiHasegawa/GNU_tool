	.text
start:
	or	sp, r0, (stack)
	bsr	(main)
	nop

	.global	__main
__main:
	jmp	link
	
	

	.text
start:
	or	sp, r0, (stack)
	bsr	(main)
	nop
end:
	nop

	.global	__main
__main:
	jmp	link
	
	

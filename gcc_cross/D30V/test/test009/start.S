	.text
start:
	or	sp, r0, (stack)
	bsr	(main)
	.word	0x0e000005
	nop
end:
	nop

	.global	__main
__main:
	jmp	link
	
	

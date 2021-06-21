	.text
start:
	mov.w	#a, r0
	mov.w	@r0, r1
	mov.w	#tmp, r0
	mov.w	r1, @r0
	mov.w	#b, r0
	mov.w	@r0, r1
	mov.w	#a, r0
	mov.w	r1, @r0
	mov.w	#tmp, r0
	mov.w	@r0, r1
	mov.w	#b, r0
	mov.w	r1, @r0
	nop
end:	
	nop

	.data
a:
	.word	0x1234

b:
	.word	0x5678

	.section .bss
tmp:	
	.space	2

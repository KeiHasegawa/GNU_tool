	.text
start:
	or	r2, r0, (_bss_start)
	or	r3, r0, (_bss_end)
.L0:
	cmpeq	f0, r2, r3
	bra/tx .L1
	stb	r0, @(r2, r0)
	add	r2, r2, 1
	bra	.L0
.L1:	
	or	sp, r0, (_stack)
	bsr	(main)
	nop
	.word	0xbadbeef0

	.global	__main
__main:
	jmp	link
	
	.global	printf
printf:
	.word	0xbadbeef1
	jmp	link

	.global	puts
puts:
	.word	0xbadbeef2
	jmp	link

	.global	putchar
putchar:
	.word	0xbadbeef3
	jmp	link
	
	

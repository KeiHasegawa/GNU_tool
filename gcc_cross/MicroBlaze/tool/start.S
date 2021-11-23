	.text
	.global _start
start:
	nop
	la	r1, r0, _stack-16

      	brlid	r15, main
	nop
	.word	0xbadbeef0

	.global	printf
printf:
	.word	0xbadbeef1
	rtsd	r15,8
	nop

	.global	puts
puts:
	.word	0xbadbeef2
	rtsd	r15,8
	nop
	
	.global	putchar
putchar:
	.word	0xbadbeef3
	rtsd	r15,8
	nop
	

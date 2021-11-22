	.text
start:
	ld24 sp,#stack
	bl main
	nop
	nop
	.word 0xbadbeef0
	
	.global printf
printf:
	jmp lr
	nop
	
	.global puts
puts:
	jmp lr
	nop
	
	.global putchar
putchar:
	jmp lr
	nop
	

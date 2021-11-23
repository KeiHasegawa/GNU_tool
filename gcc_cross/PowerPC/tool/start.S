	.text
start:
	lis 1,stack@ha
	la 1,stack@l(1)
	bl main
	nop	
	.long	0x7fffbad0
	
	.global	printf
printf:
	.long	0x7fffbad1
	blr

	.global	puts
puts:
	.long	0x7fffbad2
	blr
	
	.global	putchar
putchar:
	.long	0x7fffbad3
	blr
	
	.globl memcpy
memcpy:
.LFB13:
	.cfi_startproc
	stwu 1,-48(1)
	.cfi_def_cfa_offset 48
	stw 31,44(1)
	.cfi_offset 31, -4
	mr 31,1
	.cfi_def_cfa_register 31
	stw 3,24(31)
	stw 4,28(31)
	stw 5,32(31)
	lwz 9,24(31)
	stw 9,8(31)
	b .L13
.L14:
	lwz 10,28(31)
	addi 9,10,1
	stw 9,28(31)
	lwz 9,24(31)
	addi 8,9,1
	stw 8,24(31)
	lbz 10,0(10)
	stb 10,0(9)
.L13:
	lwz 9,32(31)
	addi 10,9,-1
	stw 10,32(31)
	cmpwi 0,9,0
	bne 0,.L14
	lwz 9,8(31)
	mr 3,9
	addi 11,31,48
	lwz 31,-4(11)
	.cfi_def_cfa 11, 0
	mr 1,11
	.cfi_restore 31
	.cfi_def_cfa_register 1
	blr
	.cfi_endproc


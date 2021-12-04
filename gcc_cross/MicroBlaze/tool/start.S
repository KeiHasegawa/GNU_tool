	.text
start:
	nop
	la	r3, r0, _bss_start
	nop
	la	r4, r0, _bss_end
$L1:
	xor	r5, r3, r4
	beqi	r5, $L2
	sbi	r0, r3, 0
	addik	r3, r3, 1
	bri	$L1
$L2:	
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
	
	.globl	memcpy
	.ent	memcpy
	.type	memcpy, @function
memcpy:
	.frame	r19,12,r15		# vars= 4, regs= 1, args= 0
	.mask	0x00080000
	addik	r1,r1,-12
	swi	r19,r1,8
	addk	r19,r1,r0
	swi	r5,r19,16
	swi	r6,r19,20
	swi	r7,r19,24
	lwi	r3,r19,16
	swi	r3,r19,4
	bri	$L13
$L14:
	lwi	r4,r19,20
	addik	r3,r4,1
	swi	r3,r19,20
	lwi	r3,r19,16
	addik	r5,r3,1
	swi	r5,r19,16
	lbui	r4,r4,0
	sext8	r4,r4
	sbi	r4,r3,0
$L13:
	lwi	r3,r19,24
	addik	r4,r3,-1
	swi	r4,r19,24
	bnei	r3,$L14
	lwi	r3,r19,4
	addk	r1,r19,r0
	lwi	r19,r1,8
	addik	r1,r1,12
	rtsd	r15,8 
	nop		# Unfilled delay slot
	.end	memcpy

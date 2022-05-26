	.text
start:
	move.l	#_bss_start, %a0
	move.l	#_bss_end, %a1
.L1:
	cmp.l	%a0, %a1
	jeq	.L2
	clr.b	(%a0)
	addq.l	#1,%a0
	jra	.L1
.L2:	
	move.l	#stack, %sp
	jsr	main
	.word	0xffff

	.global printf
printf:
	.word	0xfffe
	rts

	.global puts
puts:
	.word	0xfffd
	rts

	.global putchar
putchar:
	.word	0xfffc
	rts

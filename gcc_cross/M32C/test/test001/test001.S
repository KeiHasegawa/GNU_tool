	.text
start:
	nop
	ldc	#stack, sp
	jsr.a	main
	nop
end:
	nop

main:
	rts
	

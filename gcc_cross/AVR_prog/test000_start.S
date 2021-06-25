	.text
	.global start
start:
	push r28
	push r29
	in r28,0x3d
	in r29,0x3e
	rcall	main
end:	
	nop
	

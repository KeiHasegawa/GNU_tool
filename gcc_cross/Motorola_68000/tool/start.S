	.text
	.global start
start:
	ldx	#stack
	txs
	bsr	main
end:
	.word	0xcd00


	.global printf
printf:
	.word	0xcd05
	rts

	.global puts
puts:
	.word	0xcd07
	rts

	.global putchar
putchar:
	.word	0xcd09
	rts
	

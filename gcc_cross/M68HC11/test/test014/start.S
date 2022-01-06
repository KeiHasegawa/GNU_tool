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
	.word	0xcd02
	rts

	.global puts
puts:
	.word	0xcd06
	rts

	.global putchar
putchar:
	.word	0xcd08
	rts

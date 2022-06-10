	.text
start:
	movi	stack, r15
	pta	main, tr0
	blink	tr0, r13
	nop
end:
	nop

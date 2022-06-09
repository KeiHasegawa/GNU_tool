	.text
start:
	pta	func, tr0
	blink	tr0, r0
	nop

func:
	ptabs	r0, tr0
	blink	tr0, r0

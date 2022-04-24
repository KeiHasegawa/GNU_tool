	.text
start:
	ljmp   $0x0, $label
	nop
	nop
label:
	ljmp	*start
	nop
	nop
end:
	nop

	


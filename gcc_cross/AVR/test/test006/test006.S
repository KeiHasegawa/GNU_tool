	.text
start:
	ldi r16, 0xff
	out 0x3d, r16
	ldi r16, 0xfe
	out 0x3e, r16
	rcall func
end:
	nop
	nop

func:
        ret

	
	

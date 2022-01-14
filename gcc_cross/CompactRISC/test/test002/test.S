	.text
start:
	bal (ra), func@c
	nop
end:
	nop
	

func:
	jump	 (ra)

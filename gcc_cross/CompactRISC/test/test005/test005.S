	.text
start:
	bal (ra), func@c
end:
	nop
	

func:
	jump	 (ra)

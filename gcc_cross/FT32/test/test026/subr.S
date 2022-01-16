	.text
	.global f
f:
	link   $fp,8
	sti.l  $fp,-4,$r0
	sti.l  $fp,-8,$r1
	
	ldi.l  $r1,$fp,-4
	ldi.l  $r0,$fp,-8
	add.l  $r0,$r1,$r0
	
	unlink $r29
	return

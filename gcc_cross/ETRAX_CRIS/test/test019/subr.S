	.text
	.global _f
_f:	
	subq 4,$sp
	move $srp,[$sp]
	subq 4,$sp
	move.d $r8,[$sp]
	move.d $sp,$r8
	subq 8,$sp
	
	move.d $r10,[$r8-4]
	move.d $r11,[$r8-8]
	move.d [$r8-4],$r9
	add.d [$r8-8],$r9
	move.d $r9,$r10
	
	move.d $r8,$sp
	move.d [$sp+],$r8
	jump [$sp+]

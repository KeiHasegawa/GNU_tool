	.text
	.p2align	1
	.global	f
f:
	sto.l	12($fp), $r0
	sto.l	16($fp), $r1
	
	ldo.l	$r0, 12($fp)
	ldo.l	$r1, 16($fp)
	add	$r0, $r1
	
	ret

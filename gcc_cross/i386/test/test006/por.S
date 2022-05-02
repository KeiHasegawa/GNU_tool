	.text
	.code16
	.global	power_on_reset
power_on_reset:
	ljmp	$0xf000, $my_routine

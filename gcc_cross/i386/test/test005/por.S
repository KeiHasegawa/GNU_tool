	.text
	.code16
	.global	power_on_reset
power_on_reset:
	jmp	$0xf000, $post

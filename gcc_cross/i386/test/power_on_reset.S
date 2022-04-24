	.text
	.global	power_on_reset
power_on_reset:
	lidt	pmode_IDT_info
	nop
	nop
pmode_IDT_info:
	.word 0x0000  /* limit 15:00 */
	.word 0x0000  /* base  15:00 */
	.byte 0x0f    /* base  23:16 */
	.byte 0x00    /* base  31:24 */

	

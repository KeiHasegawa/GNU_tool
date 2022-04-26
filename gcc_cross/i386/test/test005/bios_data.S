	.bss
	.global	bios_data
bios_data:
	.org	0xb0
	.global power_down_status
power_down_status:

	.org	0x100
	.global	bios_data_size
	bios_data_size = . - bios_data
	
	

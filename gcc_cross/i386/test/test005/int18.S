	.text
	.code16
	.global	int18_handler
int18_handler: # Boot Failure recovery: try the next device.
	# Reset SP and SS
	mov	$stack, %sp
	xor	%ax, %ax
	mov	%ax, %ss

	# Get the boot sequence number out of the IPL memory
	mov	$0x9ff0, %bx 	# 0x9ff0:IPL_SEG	
	mov	%bx, %ds	# Set segment
	mov	0x82,  %bx	# BX is now the sequence number
				# 0x82:IPL_SEQUENCE_OFFSET
	inc	%bx		# ++
	mov	%bx, 0x82	# Write it back
	mov	%ax, %ds	# and reset the segment to zero.

	# Carry on in the INT 19h handler, using the new sequence number
	push	%bx

	jmp  int19_next_boot

	.global	int19_relocated
int19_relocated: # Boot function, relocated

	# int19 was beginning to be really complex, so now it
	# just calls a C function that does the work

	push	%bp
	mov	%sp, %bp

	# Reset SS and SP
	mov	$stack, %sp
	xor	%ax, %ax
	mov	%ax, %ss

	# Start from the first boot device (0, in AX)
	mov	$0x9ff0, %bx 	# 0x9ff0:IPL_SEG
	mov	%bx, %ds        #  Set segment to write to the IPL memory
	mov	%ax, 0x82    	# Save the sequence number
				# 0x82:IPL_SEQUENCE_OFFSET
	mov	%ax, %ds	# and reset the segment.
	
	push	%ax

int19_next_boot:

	# Call the C code for the next boot device
	call	int19_function

	# Boot failed: invoke the boot recovery function
	int	$0x18

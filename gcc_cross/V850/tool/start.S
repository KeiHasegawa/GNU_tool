	.text
start:
	nop
	movhi hi(stack),r0,sp
	movea lo(stack),sp,sp
	movhi hi(_main),r0,r10
	movea lo(_main),r10,r10
	jarl .+4, r31 ; add 4, r31 ; jmp r10
	nop
	.short	0xd040

	.global _printf
_printf:
	.short 0xd840
	jmp [r31]

	.global _puts
_puts:
	.short 0xe040
	jmp [r31]

	.global _putchar
_putchar:
	.short 0xe840
	jmp [r31]
	

	.global _memcpy
_memcpy:
.LFB13:
	add -4,sp
.LCFI30:
	st.w r29,0[sp]
	add -16,sp
.LCFI31:
	mov sp,r29
.LCFI32:
	st.w r6,8[r29]
	st.w r7,4[r29]
	st.w r8,0[r29]
	ld.w 8[r29],r10
	st.w r10,12[r29]
	br .L13
.L14:
	ld.w 4[r29],r11
	addi 1,r11,r10
	st.w r10,4[r29]
	ld.w 8[r29],r10
	addi 1,r10,r12
	st.w r12,8[r29]
	ld.b 0[r11],r11
	shl 24,r11
	sar 24,r11
	st.b r11,0[r10]
.L13:
	ld.w 0[r29],r10
	addi -1,r10,r11
	st.w r11,0[r29]
	cmp 0,r10
	bne .L14
	ld.w 12[r29],r10
	mov r29,sp
	ld.w 16[sp],r29
	addi 20,sp,sp
	jmp [r31]


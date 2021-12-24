	.text
start:
	mov	a, #0x61
	mov	es, #0xf
	mov	es:!0xe789, a   ; *(char*)0xfe789 = 'a'

	mov	b, !0xe789	; b = *(char*)0xe789
				; equals to
	                        ; b = *(char*)0xfe789


	mov	a, #0x62
	mov	es:!0, a	; *(char*)0xf0000 = 'b'
	mov	c, !0		; b = *(char*)0
				; equals to
				; b = *(char*)0xf0000
end:	
	nop

	.text
	.global	int15_handler
int15_handler:
/*	
  cmp ah, #0x80 ; Device open
  je int15_stub
  cmp ah, #0x81 ; Device close
  je int15_stub
  cmp ah, #0x82 ; Program termination
  je int15_stub
  cmp ah, #0x90 ; Device busy interrupt. Called by Int 16h when no key available
  je int15_stub
  cmp ah, #0x91 ; Interrupt complete. Called by IRQ handlers
  je int15_stub
  pushf
#if BX_APM
  cmp ah, #0x53
  je apm_call
#endif
  push  ds
  push  es
  cmp  ah, #0x86
  je int15_handler32
  cmp  ah, #0xE8
  je int15_handler32
  pusha
#if BX_USE_PS2_MOUSE
  cmp  ah, #0xC2
  je int15_handler_mouse
#endif
  call _int15_function
int15_handler_mouse_ret:
  popa
int15_handler32_ret:
  pop   es
  pop   ds
  popf
  jmp iret_modify_cf
#if BX_APM
apm_call:
  jmp _apmreal_entry
#endif
int15_stub:
  xor ah, ah ; "operation success"
  clc
  jmp iret_modify_cf

#if BX_USE_PS2_MOUSE
int15_handler_mouse:
  call _int15_function_mouse
  jmp int15_handler_mouse_ret
#endif
	*/
	int3
	iret
	

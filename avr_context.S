#if defined ARDUINO

#if !defined(__AVR_TINY__)


#include <avr/io.h>
#include "genos/platform/avr/common/macros.inc"

/* ???: What was a reason to use aliases for common registers?
   Check the address: is it a port number (value for IN/OUT)?	*/
#if	AVR_STACK_POINTER_LO_ADDR != 0x3D	\
     || AVR_STATUS_ADDR != 0x3F
# error  "Strange address of common registers SPL, SREG"
#endif

#define jmpb_hi	r25
#define jmpb_lo	r24

#define ret_hi	r25
#define ret_lo	r24
	ASSEMBLY_CLIB_SECTION

	.global procstate_operate
	.global save_procstate
	.type	save_procstate, @function

save_procstate:
	
	push r30
	push r31 
	push r28
	push r29
	push r16
	
	in r30, AVR_STATUS_ADDR
	push r30
	
	
	push r30
	push r31 
	push r28
	push r29
	
	;load procstate_operate
	ldi r30, lo8(procstate_operate)
    ldi r31, hi8(procstate_operate)
	ld r28, Z+
	ld r29, Z+
	
	;save r0 - r27
	.irp	.L_regno, 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27
	st	Y+, r\.L_regno
	.endr
	
	;save r28, 29
	pop r31
	pop r30
	st Y+, r30
	st Y+, r31
	
	;save r30, r31
	pop r31
	pop r30
	st Y+, r30
	st Y+, r31
	
	;save SREG
	in r30, AVR_STATUS_ADDR
	st Y+,r30
	

	
  ; save stack pointer 
	in	r30, AVR_STACK_POINTER_LO_ADDR 
	in	r31, AVR_STACK_POINTER_HI_ADDR
	#if  defined(__AVR_3_BYTE_PC__) && __AVR_3_BYTE_PC__
	adiw r30, 9
	#else
	adiw r30, 8
	#endif
	st Y+,r30
	st Y+,r31
	
	
	
	; save programm counter 
	#if  defined(__AVR_3_BYTE_PC__) && __AVR_3_BYTE_PC__
	sbiw r30, 2
	ld r16, Z+
	std Y+2,r16
	ld r16, Z+
	std Y+1,r16
	ld r16, Z+
	std Y+0,r16	
	clr r16
	std Y+3,r16
	#else
	
	# error  "NEED CORRECT AVR_CONTEXT_S"

	#endif
	
	
	pop r30
	out AVR_STATUS_ADDR, r30
	
	pop r16
	pop r29
	pop r28
	pop r31
	pop r30
	
	ret
	.size	save_procstate, . - save_procstate

	
	
	
	
	.global load_procstate
	.type	load_procstate, @function

load_procstate:

;load procstate_operate
	ldi r30, lo8(procstate_operate)
    ldi r31, hi8(procstate_operate)
	ld r28, Z+
	ld r29, Z+
	
	;load r0 - r27
	.irp	.L_regno, 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26
	ld	r\.L_regno, Y+
	.endr
	
	;to SP
	adiw r28, 6

	ld r30,Y+
	ld r31,Y+
	out	AVR_STACK_POINTER_LO_ADDR, r30 
	out	AVR_STACK_POINTER_HI_ADDR, r31
	
	;PC
	#if  defined(__AVR_3_BYTE_PC__) && __AVR_3_BYTE_PC__
	ldd r27, Y+0
	push r27
	ldd r27, Y+1
	push r27
	ldd r27, Y+2
	push r27
	#else
	# error  "NEED CORRECT AVR_CONTEXT_S"
	#endif

	
	;to r27
	sbiw r28, 8
	
	
	;r27
	ld r27,Y+
	push r27
	;r28
	ld r27,Y+
	push r27
	;r29
	ld r27,Y+
	push r27
	
	;r30-31
	ld r30,Y+
	ld r31,Y+
		
	;load SREG
	ld r27,Y+
	out AVR_STATUS_ADDR, r27
	
	pop r29
	pop r28
	pop r27

	ret
	;.size	loadproc_state, . - loadproc_state


	
	

#endif /* !defined(__AVR_TINY__) */

#endif /* ARDUINO */
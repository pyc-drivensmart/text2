
	PRESERVE8
	AREA Vect, CODE, READONLY


		EXPORT	Vector_Table
	    IMPORT  SWI_Handler1
		IMPORT	IRQ_Handler1
		IMPORT	IRQ_Stack
; *****************
; Exception Vectors
; *****************

; Note: LDR PC instructions are used here, though branch (B) instructions
; could also be used, unless the ROM is at an address >32MB.

;        ENTRY
Vector_Table		
        B       Reset_Go
        LDR     PC, Undefined_Addr
        LDR     PC, SWI_Addr
        LDR     PC, Prefetch_Addr
        LDR     PC, Abort_Addr
        NOP                             ; Reserved vector
        LDR     PC, IRQ_Addr
        LDR     PC, FIQ_Addr
        
				
        IMPORT  Reset_Go           ; In sys_start.s
        
Reset_Addr      DCD     Reset_Go
Undefined_Addr  DCD     Undefined_Handler
SWI_Addr        DCD     SWI_Handler
Prefetch_Addr   DCD     Prefetch_Handler
Abort_Addr      DCD     Abort_Handler
				        DCD		  0
IRQ_Addr        DCD     IRQ_Handler
FIQ_Addr        DCD     FIQ_Handler


; ************************
; Exception Handlers
; ************************

; The following dummy handlers do not do anything useful in this example.
; They are set up here for completeness.


Undefined_Handler
        B       Undefined_Handler
SWI_Handler
		B 			SWI_Handler1 
Prefetch_Handler
        B       Prefetch_Handler
Abort_Handler
        B       Abort_Handler
		NOP
IRQ_Handler
        B       IRQ_Handler2
FIQ_Handler
        B       FIQ_Handler
				
	
			
IRQ_Handler2
	LDR SP,=IRQ_Stack 
	sub sp, sp, #72
	stmia sp, {r0 - r12}
	add r8, sp, #60
	stmdb r8, {sp, lr}^
	nop
	str lr, [r8, #0]
	mrs r6, spsr
	str r6, [r8, #4]
	str r0, [r8, #8]
	mov r0, sp
	bl IRQ_Handler1
	ldmia sp, {r0 - lr}^
	mov r0, r0
	ldr lr, [sp, #60]
	add sp, sp, #72
	subs pc, lr, #4

	END

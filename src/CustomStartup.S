.section .vectors
vic:
	/* Vectors */
	b _start		//Reset
	b .					//Undefined Instruction
	b .					//Software Interrupt
	b .					//Prefetch Abort
	b .					//Data Abort
	b .					//4-byte gap RESERVED
	b .					//IRQ
	b .					//FIQ



.section .text
.global _start
_start:

		ldr r0, =0x20200000

		@Lever GPIO25
		@GPIO25 en output
		ldr r1, [r0, #8]	@Load GPFSEL2
		mov r2, #7				@Prepare mask for output 0b111 << 6
		lsl r2, #15
		orr r1, r1, r2
		str r1, [r0, #8]

		@GPIO25 = 1
		ldr r1, [r0, #0x1C]	@Load GPSET
		mov r2, #1
		lsl r2, #25
		orr r1, r2, r1
		str r1, [r0, #0x1C]

		@Lever GPIO26
		@GPIO26 en output
		ldr r1, [r0, #8]	@Load GPFSEL2
		mov r2, #7				@Prepare mask for output 0b111 << 6
		lsl r2, #18
		orr r1, r1, r2
		str r1, [r0, #8]

		@GPIO26 = 1
		ldr r1, [r0, #0x1C]	@Load GPSET
		mov r2, #1
		lsl r2, #26
		orr r1, r2, r1
		str r1, [r0, #0x1C]

		b .


    mov sp,#0x8000
    bl notmain


end: b end

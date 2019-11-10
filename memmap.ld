MEMORY{
	MemoryRangeVectors : ORIGIN = 0x0000 , LENGTH =0x7FFF
	MemoryRange1 : ORIGIN = 0x8000 , LENGTH = 0x8000
}

SECTIONS {
	.vectors : { *(.vectors)  } > MemoryRangeVectors
	.text : { *(.text) } > MemoryRange1
	.data : { *(.data) } > MemoryRange1
	.bss : { *(.data) } > MemoryRange1
	.rodata : { *(.data) } > MemoryRange1
}

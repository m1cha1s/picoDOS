MEMORY {
    RAM(rwx) : ORIGIN = 0x21003000, LENGTH = 236k
}

ENTRY(main)


SECTIONS {
    .text : ALIGN(4) {
        *(.text)
    } > RAM

    .rodata : {
        *(.rodata)
    } > RAM

    .data : ALIGN(4) {
        *(.data)
    } > RAM
    
    .bss : ALIGN(4) {
        *(.bss)
    } > RAM
}

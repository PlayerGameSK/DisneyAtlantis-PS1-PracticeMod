INPUT(../../../.config/symbols/symbols.txt)
INPUT(../../../.config/symbols/function_symbols.txt)
INPUT(../../../.config/symbols/auto_symbols.txt)

MEMORY
{
    /* RAM locations where we'll inject the code for our replacement functions */
    Header : ORIGIN = 0x8000B0B8, LENGTH = 0x800
    AutoHook : ORIGIN = 0x8006c324, LENGTH = 0x100000
}

SECTIONS
{
    /* Custom section for compiled code */
    /* Custom section for our hook code */
    .AutoHook : 
    {
        main_hook.o(.text)
        main_hook.o(.rodata)
        main_hook.o(.rodata*)
        main_hook.o(.data)
        main_hook.o(.bss)
    } > AutoHook

    .Header : 
    {
        main.o(.text)
        main.o(.rodata)
        main.o(.rodata*)
        main.o(.data)
        main.o(.bss)
        main.o(.sdata)
        main.o(.sbss)
        main.o(.scommon)
        main.o(.main.o.*)
        *(.text) /* Last section, place any potential remaining code sections */
        *(.branch_lt)
    } > Header

    /DISCARD/ :
    {
        *(.comment)
        *(.pdr)
        *(.mdebug)
        *(.reginfo)
        *(.MIPS.abiflags)
        *(.eh_frame)
        *(.gnu.attributes)
    }
}
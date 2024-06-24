bits 32         ; nasm directive - 32 bit

extern kernel_main
global start

MODULEALIGN       equ     1<<0
MEMINFO           equ     1<<1
FLAGS             equ     MODULEALIGN | MEMINFO
MAGIC             equ     0x1BADB002
CHECKSUM          equ     -(MAGIC + FLAGS)

section .text

%include "gdt.s"

    ; Multiboot header
    align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

start:
    cli                           ; block interrupts (nb. not necessary, as QEMU boots into 32-bit protected mode with interrupts disabled)

    lgdt [gdt_descriptor]

    jmp CODE_SEG:clear_pipeline   ; Far jump to initialise the code segment register
                                  ; ref: http://www.osdever.net/tutorials/view/the-world-of-protected-mode

clear_pipeline:

    mov ax, DATA_SEG              ; Update the data segment registers
    mov ds, ax                    ; ref: https://github.com/cfenollosa/os-tutorial/blob/master/18-interrupts/boot/switch_pm.asm
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov esp, stack_space          ; Set stack pointer

    call kernel_main

.loop:
    hlt                           ; Halt the CPU
    jmp .loop


section .bss
    resb 8192   ; 8KB for stack
stack_space:
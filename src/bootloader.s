bits 32         ; nasm directive - 32 bit

global start
global load_idt
global keyboard_handler

extern kernel_main
extern kernel_keyboard_handler

MODULEALIGN       equ     1<<0
MEMINFO           equ     1<<1
FLAGS             equ     MODULEALIGN | MEMINFO
MAGIC             equ     0x1BADB002
CHECKSUM          equ     -(MAGIC + FLAGS)

section .text

    ; Multiboot header
    align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM


%include "gdt.s"


keyboard_handler:                 
    push ds
    push es
    push fs
    push gs
    pushad

    call kernel_keyboard_handler

    popad
    pop gs
    pop fs
    pop es
    pop ds

    iretd


start:
    cli                           ; Block interrupts (nb. not necessary, as QEMU boots into 32-bit protected mode with interrupts disabled)

    lgdt [gdt_descriptor]

    jmp CODE_SEGMENT:clear_pipe   ; Far jump to initialise the code segment register
                                  ; ref: http://www.osdever.net/tutorials/view/the-world-of-protected-mode
clear_pipe:
    mov ax, DATA_SEGMENT          ; Update the data segment registers
    mov ds, ax                    ; ref: https://github.com/cfenollosa/os-tutorial/blob/master/18-interrupts/boot/switch_pm.asm
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov esp, stack_space          ; Set stack pointer

    call kernel_main

loop:
    hlt                           ; Halt the CPU
    jmp loop


section .bss
    resb 8192   ; 8KB for stack
stack_space:
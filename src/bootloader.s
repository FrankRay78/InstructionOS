bits 32         ; nasm directive - 32 bit

extern kernel_main
global start

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

start:
    cli                   ; block interrupts (nb. not necessary, as QEMU boots into 32-bit protected mode with interrupts disabled)
    mov esp, stack_space  ; set stack pointer

    ; Write to QEMU's debug port
    mov al, 'F'
    out 0xe9, al

    call kernel_main
    hlt

section .bss
    resb 8192   ; 8KB for stack
stack_space:
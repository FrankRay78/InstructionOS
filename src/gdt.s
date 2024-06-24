; Global Descriptor Table (GDT)
; ref: https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf
;
; For simplicity, define two overlapping segments, 
; one code and one data, with no memory protection.
;
; Byte reference table on page 36 of bham pdf


gdt_start:

gdt_null:           ; Mandatory null descriptor
    dd 0x0          ; 'dd' means define double word (ie. 4 bytes)
    dd 0x0          ; all 8 bytes 0s

gdt_code:           ; Code segment descriptor
    ; base= 0x0, limit=0xffff
    ; 1st  flags: (present)1 (privilege)00 (descriptor type)1 -> 1001b
    ; type flags: (code)1 (conforming)0 (readable)1 (accessed)0 -> 1010b
    ; 2nd  flags: (granularity)1 (32-bit seg)1 (64-bit seg)0 (reserved)0 -> 1100b
    dw 0xffff       ; Limit (bits 0-15)
    dw 0x0          ; Base (bits 0-15)
    db 0x0          ; Base (bits 16-23)
    db 10011010b    ; 1st flags, type flags
    db 11001111b    ; 2nd flags, Limit (bits 16-19)
    db 0x0          ; Base (bits 24-31)

gdt_data:           ; Data segment descriptor
    ; Same as code segment except for the type flags:
    ; type flags: (code)0 (expand down)0 (writable)1 (accessed)0 -> 0010b
    dw 0xffff       ; Limit (bits 0-15)
    dw 0x0          ; Base (bits 0-15)
    db 0x0          ; Base (bits 16-23)
    db 10010010b    ; 1st flags, type flags
    db 11001111b    ; 2nd flags, Limit (bits 16-19)
    db 0x0          ; Base (bits 24-31)

gdt_end:            ; Allow the the assembler to calculate
                    ; the size of the GDT for the decriptor (below)


gdt_descriptor:
    dw gdt_end - gdt_start - 1  ; Size of our GDT, always one less of the true size
    dd gdt_start                ; Start address of the GDT


; Define some handy constants for the GDT segment descriptor offsets, which
; are what segment registers must contain when in protected mode. For example,
; when we set DS = 0x10 in PM, the CPU knows that we mean it to use the
; segment described at offset 0x10 (ie. 16 bytes) in our GDT, which in our
; case is the DATA segment (0x0 -> NULL; 0x08 -> CODE; 0x10 -> DATA)
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
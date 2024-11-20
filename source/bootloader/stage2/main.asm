bits 16

section _ENTRY class=CODE

extern _cstart_
global entry

entry:
    cli
    gdtr    DW 0 ; For limit storage
            DD 0 ; For base storage

    setGdt:
        XOR   EAX, EAX
        MOV   AX, DS
        SHL   EAX, 4
        ADD   EAX, ''GDT''
        MOV   [gdtr + 2], eax
        MOV  EAX, ''GDT_end''
        SUB   EAX, ''GDT''
        MOV   [gdtr], AX
        LGDT  [gdtr]
        RET
    
    ; setup stack
    mov ax, ds
    mov ss, ax
    mov sp, 0
    mov bp, sp
    sti

    ; expect boot drive in dl, send it as argument to cstart function
    xor dh, dh
    push dx
    call _cstart_

    cli            ; disable interrupts
    lgdt [gdtr]    ; load GDT register with start address of Global Descriptor Table
    mov eax, cr0 
    or al, 1       ; set PE (Protection Enable) bit in CR0 (Control Register 0)
    mov cr0, eax

    ; Perform far jump to selector 08h (offset into GDT, pointing at a 32bit PM code segment descriptor) 
    ; to load CS with proper PM32 descriptor)
    jmp 08h:PModeMain

    PModeMain:
    ; load DS, ES, FS, GS, SS, ESP

    cli
    hlt
bits 16

section _TEXT class=CODE

;
; int 10h ah=0Eh
; args: character, page
;
global _x86_Video_WriteCharTeletype
_x86_Video_WriteCharTeletype:
    ; a call frame is where the args are passed through the ->
    ; stack instead of the registers

    ; make new call frame
    push bp     ; save old call frame
    mov bp, sp  ; initialize new call frame

    ; save bx
    push bx

    ; [bp + 0] - old call frame
    ; [bp + 2] - return address (small memory model => 2 bytes)
    ; [bp + 4] - first argument (character)
    ; [bp + 6] - second argument (page)
    ; note: bytes are converted to words (you can't push a single byte on the stack)
    mov ah, 0Eh
    mov al, [bp + 4] ; char to print. first argument
    mov bh, [bp + 6] ; page to print to. Second argument
    
    int 10h

    ; restore bx
    pop bx

    ; restore old call frame
    mov sp, bp
    pop bp
    ret

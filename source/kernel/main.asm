org 0x0
bits 16


%define ENDL 0x0D, 0x0A

start:
    ; print hello world message
    mov si, msg_hello
    call puts

.halt:
    cli
    hlt

install_keyboard_handler:
    push ax
    cli
    mov ax, 0x09
    mov es, ax
    mov di, 

keyboard_handler:
    push ax
    in al, 0x60
    mov ah, 0x0e
    int 0x10
    pop ax
    iret

;
; Prints a string to the screen
; Params:
;   - ds:si points to string
;
puts:
    ; save registers we will modify
    push si
    push ax
    push bx

.loop:
    lodsb               ; loads next character in al
    or al, al           ; verify if next character is null?
    jz .done

    mov ah, 0x0E        ; call bios interrupt
    mov bh, 0           ; set page number to 0
    int 0x10

    jmp .loop

.done:
    pop bx
    pop ax
    pop si    
    ret


msg_hello: db 'Hello from KERNEL!!!', ENDL, 0


times 510-($-$$) db 0
dw 0AA55h

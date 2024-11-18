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

data:
    keyboard_handler_backup db 0

install_keyboard_handler:
    push ax     ; Save the current state of the AX register
    cli        ; Disable interrupts to prevent the current handler from being called while we change it
    mov ax, 0x09 ; Set the interrupt vector for the keyboard
    mov es, ax
    mov di, [es:0x00] ; Get the current handler
    mov [keyboard_handler_backup], di ; Save the current handler
    mov di, keyboard_handler ; Set the new handler to our interrupt handler
    mov [es:0x00], di
    sti        ; Enable interrupts again
    pop ax      ; Restore the AX register
    ret

restore_keyboard_handler:
    push ax     ; Save the current state of the AX register
    cli        ; Disable interrupts to prevent the current handler from being called while we change it
    mov ax, 0x09 ; Set the interrupt vector for the keyboard
    mov es, ax
    mov di, [keyboard_handler_backup] ; Get the original handler
    mov [es:0x00], di
    sti        ; Enable interrupts again
    pop ax      ; Restore the AX register
    ret

keyboard_handler:
    push ax     ; Save the current state of the AX register
    in al, 0x60 ; Read the scancode from the keyboard
    mov ah, 0x0e ; Set the teletype output function in the BIOS
    int 0x10   ; Call the BIOS to print the character
    pop ax      ; Restore the AX register
    iret       ; Return from the interrupt handler

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

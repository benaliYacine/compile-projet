TITLE GeneratedProgram
PILE SEGMENT STACK
    DW 100 DUP(?)
PILE ENDS

DONNEE SEGMENT
    DIX DW 10
    MOINS_UN DW -1
    RETOUR_LIGNE DB 0Dh, 0Ah, '$'
    PROMPT_CHAR DB '?' , '$'
    TEMP_CHAR DB ?, '$'
    BUFFER_ENTREE LABEL BYTE
      MAX_CHARS  DB 81
      CHARS_LUS DB ?
      DONNEES_BUFFER DB 81 DUP('$')
    EST_NEGATIF DB 0

    MSG0 DB "The sum is $"
    MSG1 DB "Is greater flag: $"

    T2 DW ?
    temp_cond2 DW ?
DONNEE ENDS

LECODE SEGMENT
Debut:
    ASSUME CS:LECODE, DS:DONNEE, SS:PILE
    MOV AX, DONNEE
    MOV DS, AX
    MOV ES, AX

L0: ; (WRITE, "The sum is ", 30, vide)
    lea dx, MSG0
    call display_message
    mov ax, 30
    call display_integer
    call print_newline

L1: ; (BLE, 13, 30, T2)
    mov ax, 30
    cmp ax, T2
    jle L13

L2: ; (BR, 14, vide, vide)
    jmp L14

L3: ; (BZ, 17, 0, vide)
    mov ax, 0
    cmp ax, 0
    jz L17

L4: ; (BR, 18, vide, vide)
    jmp L18

L5: ; (WRITE, "Is greater flag: ", 0, vide)
    lea dx, MSG1
    call display_message
    mov ax, 0
    call display_integer
    call print_newline

L6: ; (<=, 1, 4, temp_cond2)
L7: ; (BZ, 25, temp_cond2, vide)
    mov ax, temp_cond2
    cmp ax, 0
    jz L25

L8: ; (BR, 20, vide, vide)
    jmp L20


Fin_Programme:
    MOV AH, 4Ch
    INT 21h

; procédure to display string at DS:DX (must be $-terminated)
display_message proc near
    push ax
    mov ah, 09h
    int 21h
    pop ax
    ret
display_message endp

print_newline proc near
    push ax
    push dx
    lea dx, RETOUR_LIGNE
    call display_message
    pop dx
    pop ax
    ret
print_newline endp

; procedure to display integer in AX (handles negative)
display_integer proc near
    push ax
    push bx
    push cx
    push dx
    cmp ax, 0
    jge disp_positive_num_9
    push ax
    mov dl, '-'
    mov ah, 02h
    int 21h
    pop ax
    neg ax
disp_positive_num_9:
    xor cx, cx
    mov bx, 10
disp_convert_loop_9:
    xor dx, dx
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne disp_convert_loop_9
disp_print_loop_9:
    pop dx
    add dl, '0'
    mov ah, 02h
    int 21h
    loop disp_print_loop_9
    pop dx
    pop cx
    pop bx
    pop ax
    ret
display_integer endp

; procedure to scan integer into AX (handles negative & backspace)
scan_integer proc near
    push bx
    push cx
    push dx
    push si

    mov cx, 0             ; CX will hold the number
    mov EST_NEGATIF, 0     ; Flag for negative number
    mov si, 0             ; Digit counter

scan_read_char_loop_9:
    mov ah, 01h           ; Read char with echo
    int 21h               ; AL = char

    cmp al, 0Dh           ; Carriage return?
    je scan_end_input_9

    cmp al, '-'           ; Minus sign?
    je scan_handle_minus_9

    cmp al, 8             ; Backspace?
    je scan_handle_backspace_9

    cmp al, '0'
    jl scan_ignore_char_9
    cmp al, '9'
    jg scan_ignore_char_9

    ; It's a digit
    cmp si, 5             ; Limit to 5 digits (max ~32767)
    jge scan_ignore_char_9 ; Too many digits, ignore

    inc si
    sub al, '0'           ; Convert char to number
    mov ah, 0
    push ax               ; Save digit

    mov ax, cx            ; AX = current number
    mov bx, DIX
    mul bx                ; AX = current number * 10
    jc scan_overflow_9   ; Check for overflow from mul
    mov cx, ax

    pop ax                ; Restore digit
    add cx, ax            ; CX = CX + digit
    jc scan_overflow_9   ; Check for overflow from add
    jmp scan_read_char_loop_9

scan_handle_minus_9:
    cmp si, 0             ; Minus only allowed as first char
    jne scan_ignore_char_9
    cmp EST_NEGATIF, 1     ; Only one minus allowed
    je scan_ignore_char_9
    mov EST_NEGATIF, 1
    jmp scan_read_char_loop_9

scan_handle_backspace_9:
    cmp si, 0             ; Anything to backspace?
    je scan_read_char_loop_9

    dec si                ; Decrement digit count
    ; Erase char on screen: print backspace, space, backspace
    mov dl, 08h
    mov ah, 02h
    int 21h
    mov dl, ' '
    mov ah, 02h
    int 21h
    mov dl, 08h
    mov ah, 02h
    int 21h

    mov ax, cx
    xor dx, dx
    mov bx, DIX
    div bx                ; AX = CX / 10
    mov cx, ax
    cmp si, 0             ; If all digits removed and was negative
    jne scan_read_char_loop_9
    mov EST_NEGATIF, 0     ; Reset minus flag if no digits left
    jmp scan_read_char_loop_9

scan_overflow_9:
    ; Handle overflow - maybe clear CX and restart, or error
    ; For now, just ignore and continue (bad number will result)
    mov cx, 0 ; Clear to avoid partial large number
    mov si, 0
    mov EST_NEGATIF, 0
    ; Could print an error message here
    jmp scan_read_char_loop_9

scan_ignore_char_9:
    mov dl, 07h           ; Bell for invalid char
    mov ah, 02h
    int 21h
    ; also erase the bad char from screen
    mov dl, 08h
    mov ah, 02h
    int 21h
    mov dl, ' '
    mov ah, 02h
    int 21h
    mov dl, 08h
    mov ah, 02h
    int 21h
    jmp scan_read_char_loop_9

scan_end_input_9:
    cmp EST_NEGATIF, 1
    jne scan_positive_res_9
    cmp cx, 0 ; if cx is 0, -0 is 0
    je scan_positive_res_9
    neg cx
scan_positive_res_9:
    mov ax, cx            ; Result in AX

    pop si
    pop dx
    pop cx
    pop bx
    ret
scan_integer endp

; Procedure to read a string using DOS buffered input (AH=0Ah)
; Expects DX to point to a buffer: max_len, actual_len, data...
scan_string_proc proc near
    push ax
    mov ah, 0Ah
    int 21h
    pop ax
    ret
scan_string_proc endp

LECODE ENDS
END Debut

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

    MSG0 DB "$$"
    MSG1 DB "%$"
    MSG2 DB "#$"
    MSG3 DB "&$"

    3.14159 DW ?
    T2 DW ?
    GreetingStr DB 81 DUP('$')
    AnotherChar DB ?
    T7 DW ?
    0.001 DW ?
    T8 DW ?
    -2.5 DW ?
    T9 DW ?
    MaxCount DW ?
    T12 DW ?
    LoopVar DW ?
DONNEE ENDS

LECODE SEGMENT
Debut:
    ASSUME CS:LECODE, DS:DONNEE, SS:PILE
    MOV AX, DONNEE
    MOV DS, AX
    MOV ES, AX

L0: ; (+, 3.14159, 3.14159, T2)
    mov ax, 3.14159
    add ax, 3.14159
    mov T2, ax

L1: ; (x, "Enter an integer for VarInt2: ", 100, vide)
L2: ; (READ, "$", 100, vide)
    lea dx, MSG0
    call display_message
    call scan_integer
    mov 100, ax
    call print_newline

L3: ; (x, "Enter a float for VarFloat2: ", 2, vide)
L4: ; (READ, "%", 2, vide)
    lea dx, MSG1
    call display_message
    call scan_integer
    mov 2, ax
    call print_newline

L5: ; (x, "Enter a string for GreetingStr: ", GreetingStr, vide)
L6: ; (READ, "#", GreetingStr, vide)
    lea dx, MSG2
    call display_message
    lea dx, BUFFER_ENTREE
    call scan_string_proc
    ; Copy BUFFER_ENTREE to GreetingStr and ensure $-termination
    lea si, DONNEES_BUFFER
    lea di, GreetingStr
    mov cl, CHARS_LUS
    xor ch, ch ; CX = actual_len
    cmp cl, 0
    je read_str_done_6
    rep movsb ; Copy string
read_str_done_6:
    mov byte ptr [di], '$' ; Terminate with $
    call print_newline

L7: ; (x, "Enter a char for AnotherChar: ", AnotherChar, vide)
L8: ; (READ, "&", AnotherChar, vide)
    lea dx, MSG3
    call display_message
    mov ah, 01h ; Read char with echo
    int 21h
    mov AnotherChar, al
    call print_newline

L9: ; (+, T2, 2, T7)
    mov ax, T2
    add ax, 2
    mov T7, ax

L10: ; (-, T7, 0.001, T8)
    mov ax, T7
    sub ax, 0.001
    mov T8, ax

L11: ; (*, T8, -2.5, T9)
    mov ax, T8
    mul -2.5
    mov T9, ax

L12: ; (x, "VarInt1 value is ", 10, vide)
L13: ; (x, "VarInt2 (after read) is ", 100, vide)
L14: ; (x, "ResultInt is ", 550, vide)
L15: ; (x, "VarFloat1 value is ", T2, vide)
L16: ; (x, "VarFloat2 (after read) is ", 2, vide)
L17: ; (x, "ResultFloat is ", T9, vide)
L18: ; (x, "VarChar1 value is ", 'S', vide)
L19: ; (x, "AnotherChar (after read) is ", AnotherChar, vide)
L20: ; (x, "VarString1 value is ", "Initial String", vide)
L21: ; (x, "GreetingStr (after read) is ", GreetingStr, vide)
L22: ; (x, "Constant WelcomeMsg is ", "Welcome to PHYLOG", vide)
L23: ; (x, "Constant SignChar is ", '!', vide)
L24: ; (BL, 51, 100, 0)
    mov ax, 100
    cmp ax, 0
    jl L51

L25: ; (BR, 52, vide, vide)
    jmp L52

L26: ; (BNE, 55, 100, MaxCount)
    mov ax, 100
    cmp ax, MaxCount
    jne L55

L27: ; (BR, 56, vide, vide)
    jmp L56

L28: ; (BNZ, 59, 0, vide)
    mov ax, 0
    cmp ax, 0
    jnz L59

L29: ; (BR, 60, vide, vide)
    jmp L60

L30: ; (BZ, 64, 0, vide)
    mov ax, 0
    cmp ax, 0
    jz L64

L31: ; (BZ, 64, 0, vide)
    mov ax, 0
    cmp ax, 0
    jz L64

L32: ; (BR, 65, vide, vide)
    jmp L65

L33: ; (BZ, 70, 0, vide)
    mov ax, 0
    cmp ax, 0
    jz L70

L34: ; (x, "VarInt2 is positive AND not equal to MaxCount. Value ", 100, vide)
L35: ; (BR, 73, vide, vide)
    jmp L73

L36: ; (x, "VarInt2 is negative OR equal to MaxCount. Value ", 100, vide)
L37: ; (BGE, 76, T9, 0)
    mov ax, T9
    cmp ax, 0
    jge L76

L38: ; (BR, 77, vide, vide)
    jmp L77

L39: ; (BZ, 80, 0, vide)
    mov ax, 0
    cmp ax, 0
    jz L80

L40: ; (x, "ResultFloat is negative: ", T9, vide)
L41: ; (BR, 88, vide, vide)
    jmp L88

L42: ; (BNE, 83, T9, 0)
    mov ax, T9
    cmp ax, 0
    jne L83

L43: ; (BR, 84, vide, vide)
    jmp L84

L44: ; (BZ, 87, 0, vide)
    mov ax, 0
    cmp ax, 0
    jz L87

L45: ; (x, "ResultFloat is zero. ", T9, vide)
L46: ; (BR, 88, vide, vide)
    jmp L88

L47: ; (x, "ResultFloat is positive: ", T9, vide)
L48: ; (BNE, 91, 1, 1)
    mov ax, 1
    cmp ax, 1
    jne L91

L49: ; (BR, 92, vide, vide)
    jmp L92

L50: ; (BNE, 95, 0, 0)
    mov ax, 0
    cmp ax, 0
    jne L95

L51: ; (BR, 96, vide, vide)
    jmp L96

L52: ; (BNZ, 100, 0, vide)
    mov ax, 0
    cmp ax, 0
    jnz L100

L53: ; (BNZ, 100, 0, vide)
    mov ax, 0
    cmp ax, 0
    jnz L100

L54: ; (BR, 101, vide, vide)
    jmp L101

L55: ; (BZ, 112, 1, vide)
    mov ax, 1
    cmp ax, 0
    jz L112

L56: ; (x, "IsValid is true OR HasError is false (expected).", 1, vide)
L57: ; (BG, 107, 10, T12)
    mov ax, 10
    cmp ax, T12
    jg L107

L58: ; (BR, 108, vide, vide)
    jmp L108

L59: ; (BZ, 111, 0, vide)
    mov ax, 0
    cmp ax, 0
    jz L111

L60: ; (x, "Sum of first two array elements is LE MaxCount+10. Sum: ", 10, vide)
L61: ; (BR, 111, vide, vide)
    jmp L111

L62: ; (BR, 112, vide, vide)
    jmp L112

L63: ; (x, "Starting FOR loop to populate IntArray further and DISPLAY:", LoopVar, vide)
L64: ; (BG, 116, 10, 4)
    mov ax, 10
    cmp ax, 4
    jg L116

L65: ; (BR, 117, vide, vide)
    jmp L117

L66: ; (BZ, 121, 10, vide)
    mov ax, 10
    cmp ax, 0
    jz L121

L67: ; (BR, 119, vide, vide)
    jmp L119


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
    jge disp_positive_num_68
    push ax
    mov dl, '-'
    mov ah, 02h
    int 21h
    pop ax
    neg ax
disp_positive_num_68:
    xor cx, cx
    mov bx, 10
disp_convert_loop_68:
    xor dx, dx
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne disp_convert_loop_68
disp_print_loop_68:
    pop dx
    add dl, '0'
    mov ah, 02h
    int 21h
    loop disp_print_loop_68
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

scan_read_char_loop_68:
    mov ah, 01h           ; Read char with echo
    int 21h               ; AL = char

    cmp al, 0Dh           ; Carriage return?
    je scan_end_input_68

    cmp al, '-'           ; Minus sign?
    je scan_handle_minus_68

    cmp al, 8             ; Backspace?
    je scan_handle_backspace_68

    cmp al, '0'
    jl scan_ignore_char_68
    cmp al, '9'
    jg scan_ignore_char_68

    ; It's a digit
    cmp si, 5             ; Limit to 5 digits (max ~32767)
    jge scan_ignore_char_68 ; Too many digits, ignore

    inc si
    sub al, '0'           ; Convert char to number
    mov ah, 0
    push ax               ; Save digit

    mov ax, cx            ; AX = current number
    mov bx, DIX
    mul bx                ; AX = current number * 10
    jc scan_overflow_68   ; Check for overflow from mul
    mov cx, ax

    pop ax                ; Restore digit
    add cx, ax            ; CX = CX + digit
    jc scan_overflow_68   ; Check for overflow from add
    jmp scan_read_char_loop_68

scan_handle_minus_68:
    cmp si, 0             ; Minus only allowed as first char
    jne scan_ignore_char_68
    cmp EST_NEGATIF, 1     ; Only one minus allowed
    je scan_ignore_char_68
    mov EST_NEGATIF, 1
    jmp scan_read_char_loop_68

scan_handle_backspace_68:
    cmp si, 0             ; Anything to backspace?
    je scan_read_char_loop_68

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
    jne scan_read_char_loop_68
    mov EST_NEGATIF, 0     ; Reset minus flag if no digits left
    jmp scan_read_char_loop_68

scan_overflow_68:
    ; Handle overflow - maybe clear CX and restart, or error
    ; For now, just ignore and continue (bad number will result)
    mov cx, 0 ; Clear to avoid partial large number
    mov si, 0
    mov EST_NEGATIF, 0
    ; Could print an error message here
    jmp scan_read_char_loop_68

scan_ignore_char_68:
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
    jmp scan_read_char_loop_68

scan_end_input_68:
    cmp EST_NEGATIF, 1
    jne scan_positive_res_68
    cmp cx, 0 ; if cx is 0, -0 is 0
    je scan_positive_res_68
    neg cx
scan_positive_res_68:
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

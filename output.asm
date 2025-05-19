TITLE GeneratedProgram
.model small
.stack 100h

.data
    ten dw 10
    minus_one dw -1
    newline db 0Dh, 0Ah, '$'
    prompt_char db '?' , '$' ; Default prompt for single char read
    temp_char db ?, '$'
    input_buffer_dos label byte
      max_chars  db 81      ; Max chars to read (80 + CR)
      actual_len db ?       ; Actual number of chars read (excluding CR)
      buffer_data db 81 dup('$') ; Buffer for data, init with $ for safety
    make_minus db 0 ; For scan_integer

msg0 db "Enter an integer for VarInt2: $"
msg1 db "$$"
msg2 db "Enter a float for VarFloat2: $"
msg3 db "%$"
msg4 db "Enter a string for GreetingStr: $"
msg5 db "#$"
msg6 db "Enter a char for AnotherChar: $"
msg7 db "&$"
msg8 db "VarInt1 value is $"
msg9 db "VarInt2 (after read) is $"
msg10 db "ResultInt is $"
msg11 db "VarFloat1 value is $"
msg12 db "VarFloat2 (after read) is $"
msg13 db "ResultFloat is $"
msg14 db "VarChar1 value is $"
msg15 db "AnotherChar (after read) is $"
msg16 db "VarString1 value is $"
msg17 db "GreetingStr (after read) is $"
msg18 db "Constant WelcomeMsg is $"
msg19 db "Constant SignChar is $"
msg20 db "VarInt2 is positive AND not equal to MaxCount. Value $"
msg21 db "VarInt2 is negative OR equal to MaxCount. Value $"
msg22 db "ResultFloat is negative: $"
msg23 db "ResultFloat is zero. $"
msg24 db "ResultFloat is positive: $"
msg25 db "IsValid is true OR HasError is false (expected).$"
msg26 db "Sum of first two array elements is LE MaxCount+10. Sum: $"
msg27 db "Starting FOR loop to populate IntArray further and DISPLAY:$"
msg28 db "ResultInt after adding (-10) is $"
msg29 db "ResultFloat after dividing by (-2.0) is $"
msg30 db "Final message: $"

3.14159 dw ?
T2 dw ?
GreetingStr db 81 dup('$') ; Buffer for string, $ terminated
AnotherChar db ?
T7 dw ?
0.001 dw ?
T8 dw ?
-2.5 dw ?
T9 dw ?
MaxCount dw ?
T12 dw ?
LoopVar dw ?
T15 dw ?

.code
start:
    mov ax, @data
    mov ds, ax
    mov es, ax ; For string operations if needed by scan/print

L0: ; (*, 3.14159, 2, T2)
    mov ax, 3.14159
    mov bx, 2
    mul bx
    mov T2, ax

L1: ; (WRITE, "Enter an integer for VarInt2: ", 100, vide)
    lea dx, msg0
    call display_message
    mov ax, 100
    call display_integer
    call print_newline

L2: ; (READ, "$", 100, vide)
    lea dx, msg1
    call display_message
    call scan_integer
    mov 100, ax
    call print_newline

L3: ; (WRITE, "Enter a float for VarFloat2: ", 2, vide)
    lea dx, msg2
    call display_message
    mov ax, 2
    call display_integer
    call print_newline

L4: ; (READ, "%", 2, vide)
    lea dx, msg3
    call display_message
    call scan_integer
    mov 2, ax
    call print_newline

L5: ; (WRITE, "Enter a string for GreetingStr: ", GreetingStr, vide)
    lea dx, msg4
    call display_message
    lea dx, GreetingStr
    call display_message
    call print_newline

L6: ; (READ, "#", GreetingStr, vide)
    lea dx, msg5
    call display_message
    lea dx, input_buffer_dos
    call scan_string_proc
    ; Copy input_buffer_dos to GreetingStr and ensure $-termination
    lea si, input_buffer_dos.buffer_data
    lea di, GreetingStr
    mov cl, [input_buffer_dos.actual_len]
    xor ch, ch ; CX = actual_len
    cmp cl, 0
    je read_str_done_6
    rep movsb ; Copy string
read_str_done_6:
    mov byte ptr [di], '$' ; Terminate with $
    call print_newline

L7: ; (WRITE, "Enter a char for AnotherChar: ", AnotherChar, vide)
    lea dx, msg6
    call display_message
    mov dl, AnotherChar
    mov ah, 02h
    int 21h
    call print_newline

L8: ; (READ, "&", AnotherChar, vide)
    lea dx, msg7
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

L12: ; (WRITE, "VarInt1 value is ", 10, vide)
    lea dx, msg8
    call display_message
    mov ax, 10
    call display_integer
    call print_newline

L13: ; (WRITE, "VarInt2 (after read) is ", 100, vide)
    lea dx, msg9
    call display_message
    mov ax, 100
    call display_integer
    call print_newline

L14: ; (WRITE, "ResultInt is ", 550, vide)
    lea dx, msg10
    call display_message
    mov ax, 550
    call display_integer
    call print_newline

L15: ; (WRITE, "VarFloat1 value is ", T2, vide)
    lea dx, msg11
    call display_message
    mov ax, T2
    call display_integer
    call print_newline

L16: ; (WRITE, "VarFloat2 (after read) is ", 2, vide)
    lea dx, msg12
    call display_message
    mov ax, 2
    call display_integer
    call print_newline

L17: ; (WRITE, "ResultFloat is ", T9, vide)
    lea dx, msg13
    call display_message
    mov ax, T9
    call display_integer
    call print_newline

L18: ; (WRITE, "VarChar1 value is ", 'S', vide)
    lea dx, msg14
    call display_message
    mov dl, 83 ; char 'S'
    mov ah, 02h
    int 21h
    call print_newline

L19: ; (WRITE, "AnotherChar (after read) is ", AnotherChar, vide)
    lea dx, msg15
    call display_message
    mov dl, AnotherChar
    mov ah, 02h
    int 21h
    call print_newline

L20: ; (WRITE, "VarString1 value is ", "Initial String", vide)
    lea dx, msg16
    call display_message
    mov ax, "Initial String"
    call display_integer
    call print_newline

L21: ; (WRITE, "GreetingStr (after read) is ", GreetingStr, vide)
    lea dx, msg17
    call display_message
    lea dx, GreetingStr
    call display_message
    call print_newline

L22: ; (WRITE, "Constant WelcomeMsg is ", "Welcome to PHYLOG", vide)
    lea dx, msg18
    call display_message
    mov ax, "Welcome to PHYLOG"
    call display_integer
    call print_newline

L23: ; (WRITE, "Constant SignChar is ", '!', vide)
    lea dx, msg19
    call display_message
    mov dl, 33 ; char '!'
    mov ah, 02h
    int 21h
    call print_newline

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

L34: ; (WRITE, "VarInt2 is positive AND not equal to MaxCount. Value ", 100, vide)
    lea dx, msg20
    call display_message
    mov ax, 100
    call display_integer
    call print_newline

L35: ; (BR, 73, vide, vide)
    jmp L73

L36: ; (WRITE, "VarInt2 is negative OR equal to MaxCount. Value ", 100, vide)
    lea dx, msg21
    call display_message
    mov ax, 100
    call display_integer
    call print_newline

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

L40: ; (WRITE, "ResultFloat is negative: ", T9, vide)
    lea dx, msg22
    call display_message
    mov ax, T9
    call display_integer
    call print_newline

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

L45: ; (WRITE, "ResultFloat is zero. ", T9, vide)
    lea dx, msg23
    call display_message
    mov ax, T9
    call display_integer
    call print_newline

L46: ; (BR, 88, vide, vide)
    jmp L88

L47: ; (WRITE, "ResultFloat is positive: ", T9, vide)
    lea dx, msg24
    call display_message
    mov ax, T9
    call display_integer
    call print_newline

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

L56: ; (WRITE, "IsValid is true OR HasError is false (expected).", 1, vide)
    lea dx, msg25
    call display_message
    mov ax, 1
    call display_integer
    call print_newline

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

L60: ; (WRITE, "Sum of first two array elements is LE MaxCount+10. Sum: ", 10, vide)
    lea dx, msg26
    call display_message
    mov ax, 10
    call display_integer
    call print_newline

L61: ; (BR, 111, vide, vide)
    jmp L111

L62: ; (BR, 112, vide, vide)
    jmp L112

L63: ; (WRITE, "Starting FOR loop to populate IntArray further and DISPLAY:", LoopVar, vide)
    lea dx, msg27
    call display_message
    mov ax, LoopVar
    call display_integer
    call print_newline

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

L68: ; (WRITE, "ResultInt after adding (-10) is ", 10, vide)
    lea dx, msg28
    call display_message
    mov ax, 10
    call display_integer
    call print_newline

L69: ; (/, T2, -2, T15)
    mov ax, T2
    cwd
    mov bx, -2
    div bx
    mov T15, ax

L70: ; (WRITE, "ResultFloat after dividing by (-2.0) is ", T15, vide)
    lea dx, msg29
    call display_message
    mov ax, T15
    call display_integer
    call print_newline

L71: ; (WRITE, "Final message: ", "Initial String", vide)
    lea dx, msg30
    call display_message
    mov ax, "Initial String"
    call display_integer
    call print_newline


exit_program:
    mov ah, 4Ch
    int 21h

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
    lea dx, newline
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
    jge disp_positive_num_72
    push ax
    mov dl, '-'
    mov ah, 02h
    int 21h
    pop ax
    neg ax
disp_positive_num_72:
    xor cx, cx
    mov bx, 10
disp_convert_loop_72:
    xor dx, dx
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne disp_convert_loop_72
disp_print_loop_72:
    pop dx
    add dl, '0'
    mov ah, 02h
    int 21h
    loop disp_print_loop_72
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
    mov make_minus, 0     ; Flag for negative number
    mov si, 0             ; Digit counter

scan_read_char_loop_72:
    mov ah, 01h           ; Read char with echo
    int 21h               ; AL = char

    cmp al, 0Dh           ; Carriage return?
    je scan_end_input_72

    cmp al, '-'           ; Minus sign?
    je scan_handle_minus_72

    cmp al, 8             ; Backspace?
    je scan_handle_backspace_72

    cmp al, '0'
    jl scan_ignore_char_72
    cmp al, '9'
    jg scan_ignore_char_72

    ; It's a digit
    cmp si, 5             ; Limit to 5 digits (max ~32767)
    jge scan_ignore_char_72 ; Too many digits, ignore

    inc si
    sub al, '0'           ; Convert char to number
    mov ah, 0
    push ax               ; Save digit

    mov ax, cx            ; AX = current number
    mov bx, ten
    mul bx                ; AX = current number * 10
    jc scan_overflow_72   ; Check for overflow from mul
    mov cx, ax

    pop ax                ; Restore digit
    add cx, ax            ; CX = CX + digit
    jc scan_overflow_72   ; Check for overflow from add
    jmp scan_read_char_loop_72

scan_handle_minus_72:
    cmp si, 0             ; Minus only allowed as first char
    jne scan_ignore_char_72
    cmp make_minus, 1     ; Only one minus allowed
    je scan_ignore_char_72
    mov make_minus, 1
    jmp scan_read_char_loop_72

scan_handle_backspace_72:
    cmp si, 0             ; Anything to backspace?
    je scan_read_char_loop_72

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
    mov bx, ten
    div bx                ; AX = CX / 10
    mov cx, ax
    cmp si, 0             ; If all digits removed and was negative
    jne scan_read_char_loop_72
    mov make_minus, 0     ; Reset minus flag if no digits left
    jmp scan_read_char_loop_72

scan_overflow_72:
    ; Handle overflow - maybe clear CX and restart, or error
    ; For now, just ignore and continue (bad number will result)
    mov cx, 0 ; Clear to avoid partial large number
    mov si, 0
    mov make_minus, 0
    ; Could print an error message here
    jmp scan_read_char_loop_72

scan_ignore_char_72:
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
    jmp scan_read_char_loop_72

scan_end_input_72:
    cmp make_minus, 1
    jne scan_positive_res_72
    cmp cx, 0 ; if cx is 0, -0 is 0
    je scan_positive_res_72
    neg cx
scan_positive_res_72:
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

end start

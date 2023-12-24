DATA SEGMENT
    ARR DW 5, 2, 8, 1, 4   ; Example array
    ARRAY_SIZE DW 5         ; Size of the array
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    ; Sort the array using bubble sort
    MOV CX, ARRAY_SIZE
    DEC CX ; Number of passes
OUTER_LOOP:
    MOV SI, 0
INNER_LOOP:
    MOV AX, ARR[SI]
    ADD SI, 2
    CMP AX, [SI]
    JG  SWAP
    JMP CONTINUE

SWAP:
    XCHG AX, [SI]
    SUB SI, 2
    MOV [SI], AX

CONTINUE:
    LOOP INNER_LOOP
    LOOP OUTER_LOOP

    ; Display the sorted array
    MOV SI, 0
DISPLAY_LOOP:
    MOV AX, ARR[SI]
    CALL DISPLAY_NUM ; Display a 16-bit number
    INC SI
    LOOP DISPLAY_LOOP

    INT 20H  ; Terminate the program

DISPLAY_NUM PROC
    ; Display a 16-bit number in AX
    MOV CX, 5       ; Loop counter (5 digits in a 16-bit number)
    MOV BX, 10      ; Divisor (for converting binary to decimal)

DISPLAY_LOOP:
    XOR DX, DX      ; Clear DX for the division
    DIV BX          ; Divide AX by BX, result in AX, remainder in DX

    ADD DL, '0'     ; Convert the remainder to ASCII
    MOV AH, 02H     ; DOS function to print a character
    INT 21H         ; Print the character

    DEC CX          ; Decrement loop counter
    JNZ DISPLAY_LOOP; Continue loop until all digits are displayed
    RET
DISPLAY_NUM ENDP

CODE ENDS
END START

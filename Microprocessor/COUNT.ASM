DATA SEGMENT
    STRING1 DB 11H, 22H, 33H, 44H, 55H
    MSG1 DB "FOUND$"
    MSG2 DB "NOT FOUND$"
    SE DB 33H
    COUNT DB 0 ; Variable to store the count of the given number
DATA ENDS

PRINT MACRO MSG
    MOV AH, 09H
    LEA DX, MSG
    INT 21H
    INT 3
ENDM

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AL, SE
    LEA SI, STRING1
    MOV CX, 05H ; Number of elements in the array

    MOV COUNT, 0 ; Initialize count to 0

UP:
    MOV BL, [SI]
    CMP AL, BL
    JZ  FOUND
    INC SI
    LOOP UP

    PRINT MSG2
    JMP END1

FOUND:
    INC COUNT ; Increment the count when the number is found
    INC SI
    LOOP UP

END1:
    ; Print the count
    MOV AH, 09H
    LEA DX, COUNT_MSG
    INT 21H

    INT 3

COUNT_MSG DB "Count: $"

CODE ENDS
END START
CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX
    MOV AL, SE
    LEA SI, STRING1
    MOV CX, 05H ; Number of elements in the array

UP:
    MOV BL, [SI]
    CMP AL, BL
    JZ  FOUND
    INC SI
    LOOP UP

    PRINT MSG2
    JMP END1

FOUND:
    ; Print "Found" message
    MOV DX, OFFSET FOUND_MSG
    MOV AH, 09H
    INT 21H

    ; Display the position
    MOV AX, SI
    CALL DISPLAY_NUM

    JMP END1

END1:
    ; Print the count
    MOV AH, 09H
    LEA DX, COUNT_MSG
    INT 21H

    INT 3

COUNT_MSG DB "Count: $"
FOUND_MSG DB "Found at position: $"
CODE ENDS
END START

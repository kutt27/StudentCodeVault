DATA SEGMENT
    MSG_ENTER1 DB 'Enter string 1: $'
    MSG_ENTER2 DB 0AH, 'Enter string 2: $'
    MSG1 DB 20, ?, 20 DUP(0)
    MSG2 DB 20, ?, 20 DUP(0)
    MSG3 DB 40 DUP(0)
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE, DS:DATA
START:
    MOV AX, DATA
    MOV DS, AX

    ; Display prompt for entering string 1
    MOV DX, OFFSET MSG_ENTER1
    MOV AH, 09H
    INT 21H

    ; Input first string
    LEA DX, MSG1
    MOV AH, 0AH
    INT 21H

    ; Output newline
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H

    ; Display prompt for entering string 2
    MOV DX, OFFSET MSG_ENTER2
    MOV AH, 09H
    INT 21H

    ; Input second string
    LEA DX, MSG2
    MOV AH, 0AH
    INT 21H

    ; Concatenate strings
    MOV SI, 2       ; index of the first element in MSG1
    MOV DI, 0       ; index for the concatenated string MSG3
    MOV CL, MSG1[1] ; length of the first string
    MOV CH, 0

    ; Copy the first string to MSG3
    loopp:
        MOV BL, MSG1[SI]
        MOV MSG3[DI], BL
        INC SI
        INC DI
        LOOP loopp

    ; Update DI to the end of MSG3
    MOV DI, SI

    MOV CL, MSG2[1] ; length of the second string
    MOV SI, 2
    ; Copy the second string to MSG3
    loopp2:
        MOV BL, MSG2[SI]
        MOV MSG3[DI], BL
        INC SI
        INC DI
        LOOP loopp2

    MOV MSG3[DI], '$'

    ; Output newline before displaying the concatenated string
    MOV DL, 0AH
    MOV AH, 02H
    INT 21H

    ; Display the concatenated string
    LEA DX, MSG3
    MOV AH, 09H
    INT 21H

    MOV AH, 4CH
    INT 21H
CODE ENDS

END START
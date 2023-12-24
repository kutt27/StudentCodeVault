DATA SEGMENT
	MSG1_ENTER DB 'Enter the first string: $'
	MSG2_ENTER DB 0AH, 'Enter the second string: $'
	MSG1 DB 20, ?, 20 DUP(0)
	MSG2 DB 20, ?, 20 DUP(0)
	MSG3 DB 40 DUP(0)
DATA ENDS
CODE SEGMENT
	ASSUME CS:CODE, DS:DATA
START:
	MOV AX, DATA
	MOV DS, AX

	; printing the first message to the terminal
	MOV DX, OFFSET MSG1_ENTER
	MOV AH, 09H
	INT 21H

	; getting the input
	LEA DX, MSG1
	MOV AH, 0AH
	INT 21H

	; printing a new line to the terminal
	MOV DL, 0AH
	MOV AH, 02H
	INT 21H

	; printing the second message to the terminal
	MOV DX, OFFSET MSG2_ENTER
	MOV AH, 09H
	INT 21H

	; getting the input value to msg2
	LEA DX, MSG2
	MOV AH, 0AH
	INT 21H

	; setting up index registers and starting the process
	MOV SI, 2
	MOV DI, 0
	MOV CL, MSG1[1]
	MOV CH, 0

	; first loop for reading the values into msg3
	LOOPP:
		MOV BL, MSG1[SI]
		MOV MSG3[DI], BL
		INC SI
		INC DI
	LOOP LOOPP

	; reseting index and values
	MOV DI, SI
	MOV CL, MSG2[1]
	MOV SI, 2

	; second loop for reading into the msg3
	LOOPP2:
		MOV BL, MSG2[SI]
		MOV MSG3[DI], BL
		INC DI
		INC SI
	LOOP LOOPP2

	; termination line
	MOV MSG3[DI], '$'

	; printing a new line to the terminal
	MOV DL, 0AH
	MOV AH, 02H
	INT 21H

	; printing the value
	LEA DX, MSG3
	MOV AH, 09H
	INT 21H

	; exiting the program
	MOV AH, 4CH
	INT 21H

CODE ENDS
END START
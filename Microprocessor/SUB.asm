DATA SEGMENT
N1 DW 0000H
N2 DW 0000H
SUM DW 0000H
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA
START:
	MOV AX, DATA
	MOV DS, AX
	MOV DX, N1
	MOV BX, N2
	SUB BX, DX
	MOV SUM, BX
	INT 3
CODE ENDS
END START
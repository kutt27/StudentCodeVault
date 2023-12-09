#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_SYMBOL_LENGTH 20

void passOne(FILE *inputFile, FILE *optabFile, FILE *symtabFile, FILE *intermediateFile, FILE *lengthFile) {
    char line[MAX_LINE_LENGTH];
    char label[MAX_SYMBOL_LENGTH];
    char opcode[MAX_SYMBOL_LENGTH];
    char operand[MAX_SYMBOL_LENGTH];
    int locctr = 0;
    int start = 0;
    int length;

    while (fgets(line, sizeof(line), inputFile)) {
        sscanf(line, "%s %s %s", label, opcode, operand);

        if (strcmp(opcode, "START") == 0) {
            start = strtol(operand, NULL, 16);
            locctr = start;
            fprintf(intermediateFile, "\t%s\t%s\t%s\n", label, opcode, operand);
        } else {
            if (strcmp(label, "**") != 0) {
                fprintf(symtabFile, "%s\t%X\n", label, locctr);
            }
            fprintf(intermediateFile, "%04X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

            if (strcmp(opcode, "END") == 0) {
                length = locctr - start;
                fprintf(lengthFile, "%d\n", length);
                break;
            }

            if (strcmp(opcode, "WORD") == 0) {
                locctr += 3;
            } else if (strcmp(opcode, "RESW") == 0) {
                locctr += 3 * atoi(operand);
            } else if (strcmp(opcode, "BYTE") == 0) {
                locctr++;
            } else if (strcmp(opcode, "RESB") == 0) {
                locctr += atoi(operand);
            } else {
                locctr += 3; // Default increment for other instructions
            }
        }
    }
}

int main() {
    FILE *inputFile, *optabFile, *symtabFile, *intermediateFile, *lengthFile;

    inputFile = fopen("input.txt", "r");
    optabFile = fopen("optab.txt", "r");
    symtabFile = fopen("symtab.txt", "w");
    intermediateFile = fopen("intermediate.txt", "w");
    lengthFile = fopen("length.txt", "w");

    if (inputFile == NULL || optabFile == NULL || symtabFile == NULL ||
        intermediateFile == NULL || lengthFile == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    passOne(inputFile, optabFile, symtabFile, intermediateFile, lengthFile);

    fclose(inputFile);
    fclose(optabFile);
    fclose(symtabFile);
    fclose(intermediateFile);
    fclose(lengthFile);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char op[3];
    char arg1[10];
    char arg2[10];
    char result[10];
} Instruction;

Instruction instructions[MAX];
int instruction_count = 0;

// Function to display instructions
void display_instructions() {
    for (int i = 0; i < instruction_count; i++) {
        printf("%s = %s %s %s\n", instructions[i].result, instructions[i].arg1, instructions[i].op, instructions[i].arg2);
    }
    printf("\n");
}

// Constant Folding
void constant_folding() {
    for (int i = 0; i < instruction_count; i++) {
        if (isdigit(instructions[i].arg1[0]) && isdigit(instructions[i].arg2[0])) {
            int val1 = atoi(instructions[i].arg1);
            int val2 = atoi(instructions[i].arg2);
            int result = 0;

            if (strcmp(instructions[i].op, "+") == 0) result = val1 + val2;
            else if (strcmp(instructions[i].op, "-") == 0) result = val1 - val2;
            else if (strcmp(instructions[i].op, "*") == 0) result = val1 * val2;
            else if (strcmp(instructions[i].op, "/") == 0 && val2 != 0) result = val1 / val2;

            sprintf(instructions[i].arg1, "%d", result);
            strcpy(instructions[i].op, "");
            strcpy(instructions[i].arg2, "");
        }
    }
}

void constant_propagation() {
    for (int i = 0; i < instruction_count; i++) {
        if (isdigit(instructions[i].arg1[0]) && instructions[i].arg2[0] == '\0') {
            for (int j = i + 1; j < instruction_count; j++) {
                if (strcmp(instructions[i].result, instructions[j].arg1) == 0)
                    strcpy(instructions[j].arg1, instructions[i].arg1);
                if (strcmp(instructions[i].result, instructions[j].arg2) == 0)
                    strcpy(instructions[j].arg2, instructions[i].arg1);
            }
        }
    }
}

// Dead Code Elimination
void dead_code_elimination() {
    int used[MAX] = {0};

    for (int i = instruction_count - 1; i >= 0; i--) {
        int is_used = 0;

        for (int j = i + 1; j < instruction_count; j++) {
            if (strcmp(instructions[i].result, instructions[j].arg1) == 0 ||
                strcmp(instructions[i].result, instructions[j].arg2) == 0) {
                is_used = 1;
                break;
            }
        }

        if (!is_used && strcmp(instructions[i].result, "result") != 0) {
            for (int k = i; k < instruction_count - 1; k++) {
                instructions[k] = instructions[k + 1];
            }
            instruction_count--;
            i--;
        }
    }
}

// Main function to optimize code
int main() {
    printf("Enter number of instructions: ");
    scanf("%d", &instruction_count);

    printf("Enter instructions (e.g., result = arg1 op arg2):\n");
    for (int i = 0; i < instruction_count; i++) {
        printf("Instruction %d: ", i + 1);
        scanf("%s = %s %s %s", instructions[i].result, instructions[i].arg1, instructions[i].op, instructions[i].arg2);
    }

    printf("\nOriginal Instructions:\n");
    display_instructions();

    constant_folding();
    constant_propagation();
    dead_code_elimination();

    printf("After Optimization:\n");
    display_instructions();

    return 0;
}

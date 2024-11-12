#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// global variables
int top = -1, label_no = 1;
char stack[30], infix[30], postfix[30], temp_str[10];

// functions to perform
void push(char ch);
char pop();
void infix_to_postfix();
void generate_code();
int get_precedence(char ch);

// driving function
int main(){
    char ch;
    int i = 0;

    printf("Enter the expression: ");
    infix[i] = '(';

    while ((ch = getchar()) != '\n'){
        infix[i++] = ch;
    }

    infix[i++] = ')';
    infix[i] = '\0';

    infix_to_postfix();
    printf("Postfix form: ");
    puts(postfix);

    generate_code();
    return 0;
}

void infix_to_postfix(){
    int i = 0, p = 0, precedence;
    char nextvar;

    while (infix[i] != '\0'){
        switch(infix[i]){
            case '(':
                push(infix[i]);
                break;
            case ')':
                while((nextvar = pop()) != '('){
                    postfix[p++] = nextvar;
                }
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                precedence = get_precedence(infix[i]);

                while (precedence <= get_precedence(stack[top])){
                    postfix[p++] = pop();
                }

                push(infix[i]);
                break;
            default:
                postfix[p++] = infix[i];
        }
        i++;
    }
    postfix[p] = '\0';
}

// generation of the code
void generate_code(){
    int i = 0;
    char operand1, operand2;

    while(postfix[i] != '\0'){
        if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^') {
            switch(postfix[i]){
                case '+': printf("add("); break;
                case '-': printf("subtract("); break;
                case '*': printf("multiply("); break;
                case '/': printf("divide("); break;
                case '^': printf("powerof("); break;
            }

            operand1 = pop();
            operand2 = pop();

            printf("%c, %c) -> t%d\n", operand2, operand1, label_no++);
        }
        else {
            push(postfix[i]);
        }
        i++;
    }
}

// precedence function

int get_precedence(char ch){
    switch(ch){
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void push(char ch){
    stack[++top] = ch;
}

char pop(){
    return stack[top--];
}

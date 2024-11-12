%{
#include<stdio.h>
#include<stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}
%token NUMBER ID
%left '+' '-' '*' '/'
%%
exp : exp '+' exp
    | exp '-' exp
    | exp '*' exp
    | exp '/' exp
    | '(' exp ')'
    | NUMBER
    | ID;
%%
int main(int argc, char *argv[])
{
    printf("Enter the expression: ");
    yyparse();
    printf("Valid Expression\n\n");
    return 0;
}

void yyerror(const char *s)
{
    printf("Invalid Expression: %s\n\n", s);
    exit(1);
}

int yywrap() 
{
    return 1;
}

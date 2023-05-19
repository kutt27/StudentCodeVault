#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int stackArr[SIZE];
int Top = -1;

void push() {
	int x;
	if(Top==SIZE-1) {
		printf("\nOverflow!!");
	}
	else {
		printf("\nEnter element to be inserted to the stack:");
		scanf("%d",&x);
		Top=Top+1;
		stackArr[Top]=x;
	}
}
 
void pop() {
	if(Top==-1) {
		printf("\nUnderflow!!");
	}
	else {
		printf("\nPopped element:  %d",stackArr[Top]);
		Top=Top-1;
	}
}
 
void printStack() {
	if(Top==-1) {
		printf("\nUnderflow!!");
	}
	else {
		printf("\nElements present in the stack: \n");
		for(int i=Top;i>=0;--i)
			printf("%d\n",stackArr[i]);
	}
}

int main(){
    int choice;
    while(1){
        printf("\nOperations performed by Stack");
		printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.End");
		printf("\n\nEnter the choice:");
		scanf("%d",&choice);
		
		switch(choice){
		    case 1: push(); break;
		    case 2: pop(); break;
		    case 3: printStack(); break;
		    case 4: exit(0);
		    default: printf("\nInvalid choice!");
		}
    }
}
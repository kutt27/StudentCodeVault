#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int items[SIZE], front = -1, rear = -1;

void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  }
}

void deQueue() {
  if (front == -1)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

// Function to print the queue
void printQueue() {
  if (rear == -1)
    printf("\nQueue is Empty!!!");
  else {
    int i;
    printf("\nQueue elements are:\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", items[i]);
  }
  printf("\n");
}

int main() {
  int choice;
  int value;
    while(1){
      printf("\nOperations performed by Queue");
      printf("\n1.Insert the element\n2.Delete the element\n3.Print the element\n4.Exit");
      printf("\n\nEnter the choice:");
      scanf("%d",&choice);
    
      switch(choice){
        case 1: 
          printf("\nEnter element to be inserted to the Queue:");
          scanf("%d",&value);
          enQueue(value);
          break;
        case 2: deQueue(); 
          break;
        case 3: printQueue(); 
          break;
        case 4: exit(0);
        default: printf("\nInvalid choice!");
    }
  }
}
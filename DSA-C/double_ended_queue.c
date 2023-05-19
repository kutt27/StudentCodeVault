#include <stdio.h>    
#define size 5  
int deque[size];    
int front = -1, rear = -1;    
   
void insert_front(int x) {    
    if((front==0 && rear==size-1) || (front==rear+1)) {    
        printf("Overflow");    
    }    
    else if((front==-1) && (rear==-1)) {    
        front = rear = 0;    
        deque[front]=x;    
    }    
    else if(front==0) {    
        front = size-1;    
        deque[front] = x;    
    }    
    else {    
        front = front-1;    
        deque[front]=x;    
    }    
}    
  
void insert_rear(int x)    
{    
    if((front==0 && rear==size-1) || (front==rear+1)) {    
        printf("Overflow");    
    }    
    else if((front==-1) && (rear==-1)) {    
        rear=0;    
        deque[rear]=x;    
    }    
    else if(rear==size-1) {    
        rear=0;    
        deque[rear]=x;    
    }    
    else {    
        rear++;    
        deque[rear]=x;    
    }    
    
}    
        
void display() {    
    int i=front;    
    printf("\nElements in a deque are: ");    
        
    while(i!=rear) {    
        printf("%d ",deque[i]);    
        i=(i+1)%size;    
    }    
     printf("%d",deque[rear]);    
}    
       
void getfront() {    
    if((front==-1) && (rear==-1)) {    
        printf("Deque is empty");    
    }    
    else {    
        printf("\nThe value of the element at front is: %d", deque[front]);    
    }    
}    
       
void getrear() {    
    if((front == -1) && (rear == -1)) {    
        printf("Deque is empty");    
    }    
    else {    
        printf("\nThe value of the element at rear is %d", deque[rear]);    
    }        
}    
       
void delete_front() {    
    if((front == -1) && (rear == -1)) {    
        printf("Deque is empty");    
    }    
    else if(front == rear) {    
        printf("\nThe deleted element is %d", deque[front]);    
        front = -1;    
        rear = -1;        
    }    
     else if(front == size-1) {    
         printf("\nThe deleted element is %d", deque[front]);    
         front = 0;    
     }    
     else {    
          printf("\nThe deleted element is %d", deque[front]);    
          front = front + 1;    
     }    
}    
       
void delete_rear() {    
    if((front==-1) && (rear==-1)) {    
        printf("Deque is empty");    
    }    
    else if(front==rear) {    
        printf("\nThe deleted element is %d", deque[rear]);    
        front=-1;    
        rear=-1;         
    }    
     else if(rear==0) {    
         printf("\nThe deleted element is %d", deque[rear]);    
         rear=size-1;    
     }    
     else {    
          printf("\nThe deleted element is %d", deque[rear]);    
          rear=rear-1;    
     }    
}    
    
int main() {    
    int n, choice;  
    printf("\nEnter 1 to insert element in front "); 
    printf("\nEnter 2 to delete element in rear "); 
    printf("\nEnter 3 to delete from front "); 
    printf("\nEnter 4 to delete from rear ");
    printf("\nEnter 5 to display"); 
    printf("\n");
    while (1) 
    { 
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);   
        switch(choice) 
        { 
        case 1: 
            printf("\nEnter element to insert : "); 
            scanf("%d",&n); 
            insert_front(n); 
            break; 
        case 2: 
            printf("\nEnter element to insert : "); 
            scanf("%d",&n); 
            insert_rear(n); 
            break; 
        case 3: 
            delete_front(); 
            break; 
        case 4: 
            delete_rear();
        case 5:
            display();
        default: 
            printf("\n Please enter valid choice"); 
        } 
    }     
} 
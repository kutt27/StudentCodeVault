#include<stdio.h>
#include<limits.h>
#define MAX 100
int idx = -1;
int pqVal[MAX];
int pqPriority[MAX];
int isEmpty(){
    return idx == -1;
}
int isFull(){
    return idx == MAX - 1;
}
void enqueue(int data, int priority)
{
    if(!isFull()){
        
        idx++;
 
        pqVal[idx] = data;
        pqPriority[idx] = priority;
    }
}
int peek()
{
    int maxPriority = INT_MIN;
    int indexPos = -1;
 
    for (int i = 0; i <= idx; i++) { 
        if (maxPriority == pqPriority[i] && indexPos > -1 && pqVal[indexPos] < pqVal[i]) 
        {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
        
        else if (maxPriority < pqPriority[i]) {
            maxPriority = pqPriority[i];
            indexPos = i;
        }
    }
    
    return indexPos;
}
void dequeue()
{
    if(!isEmpty())
    {
        int indexPos = peek();
        for (int i = indexPos; i < idx; i++) {
            pqVal[i] = pqVal[i + 1];
            pqPriority[i] = pqPriority[i + 1];
        }
 
        idx--;
        display();
    }
}

void display(){
    for (int i = 0; i <= idx; i++) {
        printf("(%d, %d)\n",pqVal[i], pqPriority[i]);
    } 
}

void main()  { 
    int n, p, choice;  
    printf("\nEnter 1 to insert element by priority "); 
    printf("\nEnter 2 to delete element by priority "); 
    printf("\nEnter 3 to display priority queue "); 
    printf("\nEnter 4 to exit");    
    while (1) 
    { 
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);   
        switch(choice) 
        { 
        case 1: 
            printf("\nEnter element to insert with priority: "); 
            scanf("%d%d",&n, &p); 
            enqueue(n); 
            break; 
        case 2:  
            dequeue(n); 
            break; 
        case 3: 
            display(); 
            break; 
        case 4: 
            exit(0); 
        default: 
            printf("\n Please enter valid choice"); 
        } 
    } 
}  


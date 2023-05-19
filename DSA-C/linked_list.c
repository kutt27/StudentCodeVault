#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next; 
}*head = NULL, *ptr;

void insert_beg(int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
    printf("\nOne node inserted!!!\n");
}

void insert_end(int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nOne node inserted!!!\n");
}

void insert_mid(int pos, int value){
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    
    struct node *temp = head;
    while(temp->next != NULL){
        if(temp->data == pos){
            ptr = temp->next;
            temp->next = newNode;
            newNode->next = ptr;
            free(ptr);
            return;
        }
        else{
            temp = temp->next;
        }  
    }
    printf("Element not found on the List");
}

void delete_beg(){
    if(head == NULL){
        printf("\nList is empty");
    }
    else{
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void delete_end(){
    if(head == NULL){
        printf("\nList is empty");
    }
    else{
        struct node *temp =head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
    }
}

void delete_pos(int pos){
    struct node *temp1 = head, *temp2;
    while(temp1->data != pos){
        if(temp1 -> next == NULL){
            printf("\nGiven node not found in the list!!!");
        }
        temp2 = temp1;
        temp1 = temp1 -> next;
   }
   temp2 -> next = temp1 -> next;
   free(temp1);
   printf("\nOne node deleted!!!\n\n");
}

void search(int value){
    struct node *temp = head;
    while(temp->next!=NULL){
        if(temp->data==value){
            printf("\nThe element is found in the list");
            return;
        }
        else{
            temp=temp->next;
        }
    }
}

void sort_LL(struct node* node){
    int local;
    if(node == NULL){
        printf("\nNo elements is present in the list!");
        return;
    }
    else{
        struct node* current = node, *temp = NULL;
        temp = current->next;
        while(temp != NULL){
            if(current -> data > temp -> data){
                local = current -> data;
                current -> data = temp -> data;
                temp -> data = local;
            }
            temp = temp -> next;
            current = current -> next;
        }
        
    }
    printf("\nSorted list: ");
    display(node);
}

void display(struct node* node){
    while(node != NULL){
        printf("%d ", node -> data);
        node = node -> next;
    }
}

int main() {
    int choice, value, value1, value2, value3, opt1;
    while(1){
        mainmenu : printf("\n\n MENU \n1. Insert\n2. Display\n3. Delete\n4. Sort\n5. Exit \n\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the value to be insert: ");
                    scanf("%d",&value);
                     while(1){
                        printf("Where you want to insert: \n1. At Beginning\n2. At End\n3. Between\n4. Go Back\nEnter your choice: ");
                        scanf("%d",&opt1);
                        switch(opt1){
                            case 1: insert_beg(value);
                                   break; 
                            case 2: insert_end(value);
                                   break;
                            case 3: printf("Enter the position where you want to insert: ");
                                   scanf("%d",&value1);
                                   insert_mid(value,value1);
                                break;
                            default: printf("\nGoing to mainmenu\n\n");
                                goto mainmenu;
                        }
                     }
            case 2: display(head);
                    break;
            case 3: printf("How do you want to Delete: \n1. From Beginning\n2. From End\n3. given_node\nEnter your choice: ");
                    scanf("%d",&value2);
                    switch(value2){
                        case 1: delete_beg();
                                break;
                        case 2: delete_end(value);
                                break;
                        case 3: printf("Enter the value which you want to delete: ");
                                scanf("%d",&value3);
                                delete_pos(value3);
                                break;
                        default: printf("\nWrong Input!! Try again!!!\n\n");
                                goto mainmenu;
                    }
                break;
            case 4: sort_LL(head);
            case 5: exit(0);
            default: printf("\nWrong input!!! Try again!!\n\n");
        }
    }
}

#include <stdio.h>
#include <stdlib.h>

struct Poly{
    int coef;
    int exp;
    struct Poly* next;
};

struct Poly* insert_poly(struct Poly* start, int coef, int exp){
    struct Poly* ptr;
    struct Poly* temp = malloc(sizeof(struct Poly));
    temp->coef = coef;
    temp->exp = exp;
    if(start == NULL || exp > start->exp){
        temp->next = start;
        start = temp;
    }
    else{
        ptr = start;
        while(ptr->next != NULL && ptr->next->exp >= exp){
            ptr = ptr -> next;
            temp -> next = ptr -> next;
            ptr -> next = temp;
        }
    }
    return start;
}

struct Poly* create(struct Poly* start){
    int i, n, exp, coef;
    printf("\nEnter the number of terms in the polynomial structure: ");
    scanf("%d",&n);
    for (int i = 0; i < n; ++i){
        printf("\nEnter the coeficient for term %d: ", i);
        scanf("%d",&coef);
        printf("\nEnter the exponent for term %d: ", i);
        scanf("%d",&exp);
        struct Poly* start = insert_poly(start, coef, exp);
    }
    return start;
}

void display(struct Node* polynomial){
    if(polynomial == NULL){
        printf("\nPolynomial is empty!");
        return;
    }
    while(polynomial!=NULL){
        printf("%dx^%d",polynomial->coef, polynomial->exp);
        polynomial = polynomial->next;
        if(polynomial->next!=NULL){
            printf(" + ");
        }
        else{
            printf("\n");
        }
    }
}

struct Poly* insert(struct Poly* start, int coef, int exp){
    struct Poly *ptr;
    struct Poly* temp = malloc(sizeof(struct Poly));
    temp->coef = coef;
    temp->exp = exp;
    if(start == NULL){
        temp->next = start;
        start = temp;
    }
    else{
        ptr = start;
        while(ptr->next != NULL){
            ptr = ptr -> next;
            temp -> next = ptr -> next;
            ptr -> next = temp;
        }
    }
    return start;
}

void poly_add(struct Poly* t1, struct Poly* t2){
    struct Node* t3 = NULL;
    while(t1!=NULL && t2!=NULL){
        if(t1->expo == t2->expo){
            t3 = insert(t3, t1->coef+t2->coef,p1->expo);
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        else if(t1->exp > t2->exp){
            t3 = insert(t3, t1->coef, t1->exp);
            t1 = t1->next;
        }
        else if(t2->exp > t1->exp){
            t3 = insert(t3, t2->coef, t2->exp);
            t2 = t2->next;
        }
    }
    while(t1 != NULL){
        t3 = insert(t3, t1->coef, t1->exp);
        t1 = t1->next;
    }
    while(t2 != NULL){
        t3 = insert(t3, t2->coef, t2->exp);
        t2 = t2->next;
    }
    printf("\nAdded polynomial is: ");
    display(t3);
}

void poly_multi(struct Poly* t1, struct Poly* t2){
    struct Poly* t3 = NULL;
    struct Poly* p2_beg;
    if(t1 != NULL || t2 != NULL){
        printf("\nGiven polynomial are empty!");
        return;
    }
    while(t1!=NULL){
        t2 = p2_beg;
        while(t2 != NULL){
            t3 = insert(t3, t1->ceof * t2->ceof, t1->exp + t2->exp);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    printf("\nMultiplied polynomial is: ");
    display(t3);
}

int main(){
    struct Poly* t1 = NULL;
    struct Poly* t2 = NULL;
    printf("\nEnter the 1st polynomial");
    t1 = create(t1);
    printf("\nEnter the 2nd polynomial");
    t2 = create(t2);
    printf("\n1st polynomial is: ");
    display(t1);
    printf("\n2nd polynomial is: ");
    display(t2);
    poly_add(t1, t2);
    poly_multi(t1, t2);
}









/*--------------------------------------------------------


/*
#include<stdio.h>
#include<stdlib.h>

struct node
{

float coef;
int expo;
struct node *link;
 
};

struct node *create(struct node *);
struct node *insert_s(struct node *,float,int);
struct node *insert(struct node *,float,int);
void display(struct node *ptr);
void poly_add(struct node *,struct node *);
void poly_mult(struct node *,struct node *);

main( )
{
 
 struct node *start1=NULL,*start2=NULL;
 
 printf("Enter polynomial 1 :\n");
 start1=create(start1);
 
 printf("Enter polynomial 2 :\n");
 start2=create(start2);
 
 printf("Polynomial 1 is : ");
 display(start1);
 
 printf("Polynomial 2 is : ");
 display(start2);
 
 poly_add(start1, start2);
 
 poly_mult(start1, start2);
 
}

//structure - create
struct node *create(struct node *start)
{
 
 int i,n,ex;
 float co;
 
 printf("Enter the number of terms : ");
 scanf("%d",&n);
 
 for(i=1;i<=n;i++)
 {
 
 printf("Enter coeficient for term %d : ",i);
 scanf("%f",&co);
 
 printf("Enter exponent for term %d : ",i);
 scanf("%d",&ex);
 start=insert_s(start,co,ex);
 
}
 
 return start;
 
}

//structure - insert
struct node *insert_s(struct node *start,float co,int ex)
{
 
 struct node *ptr,*tmp;
 
 tmp=(struct node *)malloc(sizeof(struct node));
 tmp->coef=co;
 tmp->expo=ex;
 
 //list empty or exp greater than first one
 if(start==NULL || ex > start->expo)
 {
 
 tmp->link=start;
 start=tmp;
 
 }
 else
 {
 
 ptr=start;
 
 while(ptr->link!=NULL && ptr->link->expo >= ex)
 ptr=ptr->link;
 tmp->link=ptr->link;
 ptr->link=tmp;
 
}
 
 return start;
 
}

//structure - insert
struct node *insert(struct node *start,float co,int ex)
{
 struct node *ptr,*tmp;
 
 tmp=(struct node *)malloc(sizeof(struct node));
 tmp->coef=co;
 tmp->expo=ex;
 
 //If list is empty
 if(start==NULL)
 {
 
 tmp->link=start;
 start=tmp;
 
 }
 else /*Insert at the end of the list*/
 {
 
 ptr=start;
 
 while(ptr->link!=NULL)
 ptr=ptr->link;
 tmp->link=ptr->link;
 ptr->link=tmp;
 }
 return start;
}

//display
void display(struct node *ptr)
{
 
 if(ptr==NULL)
 {
 
 printf("Zero polynomial\n");
 return;
 
 }
 
 while(ptr!=NULL)
 {
 
 printf("(%.1fx^%d)", ptr->coef,ptr->expo);
 ptr=ptr->link;
 
 if(ptr!=NULL)
 printf(" + ");
 
 else
 printf("\n");
 }
 
}





 
void poly_add(struct node *p1,struct node *p2)
{
 
 struct node *start3;
 start3=NULL;
 
 while(p1!=NULL && p2!=NULL)
 {
 
 if(p1->expo > p2->expo)
 {
 start3=insert(start3,p1->coef,p1->expo);
 p1=p1->link;
 }
 
 else if(p2->expo > p1->expo)
 {
 start3=insert(start3,p2->coef,p2->expo);
 p2=p2->link;
 }
 
 else if(p1->expo==p2->expo)
 {
 start3=insert(start3,p1->coef+p2->coef,p1->expo);
 p1=p1->link;
 p2=p2->link;
 }
 }
 
 /*if poly2 has finished and elements left in poly1*/
 while(p1!=NULL)
 {
 start3=insert(start3,p1->coef,p1->expo);
 p1=p1->link;
 }
 
 /*if poly1 has finished and elements left in poly2*/
 while(p2!=NULL)
 {
 start3=insert(start3,p2->coef,p2->expo);
 p2=p2->link;
 }
 
 printf("Added polynomial is : ");
 display(start3);
}

void poly_mult(struct node *p1, struct node *p2)
{
 struct node *start3;
 struct node *p2_beg = p2;
 start3=NULL;
 
 if(p1==NULL || p2==NULL)
 {
 printf("Multiplied polynomial is zero polynomial\n");
 return;
 }
 
 while(p1!=NULL)
 {
 p2=p2_beg;
 
 while(p2!=NULL)
 {
 start3=insert_s(start3,p1->coef*p2->coef,p1->expo+p2->expo);
 p2=p2->link;
 }
 
 p1=p1->link;
 
 }
 
 printf("Multiplied polynomial is : ");
 display(start3);
} */
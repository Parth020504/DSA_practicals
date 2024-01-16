#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*start,*p,*q;

struct node *createnode();
void insert_beg();
void insert_end();
void delete_at_specific();
void display();

void main(){
    int ch;

    while(1){
        printf("\n1.Insert at start 2.Insert at end 3.Delete at specific position 4.Display 5.Exit");

        printf("\nEnter your operation: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            insert_beg();
            break;

            case 2:
            insert_end();
            break;

            case 3:
            delete_at_specific();
            break;

            case 4:
            display();
            break;

            case 5:
            exit(0);
            break;
        }
    }
}

struct node * createnode(){
    q=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the node you want to insert: ");
    scanf("%d",&x);

    q->data=x;
    q->next=NULL;
    return q;
}

void insert_beg(){
    q=createnode();
    if(q!=NULL){
        q->next=start;
        start=q;
        printf("\nNode inserted...");
    }
}

void insert_end(){
    q=createnode();
    p=start;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    printf("\nNode inserted");
}

void delete_at_specific(){
    struct node *follow;
    int x,position;

    if(start==NULL){
        printf("\nList is empty...cannot delete");
    }

    printf("\nEnter the position at which you want to delete: ");
    scanf("%d",&position);

    x=1;
    p=start;
    follow=NULL;
    while(x!=position){
        follow=p;
        p=p->next;
        x++;
    }
    if(p==NULL){
        printf("%d position not found in the list ",position);
    }
    if(p==start){
        start=p->next;
    }
    else{
        follow->next=p->next;
        
    }
    printf("\nDeleting node %d",p->data);
    free(p);
    printf("\nNode deleted");
    
}

void display(){
    if(start==NULL){
        printf("\nList is empty...");
    }
    p=start;
    while(p!=NULL){
        printf("%d \t ",p->data);
        p=p->next;
    }
}
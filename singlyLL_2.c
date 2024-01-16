#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*p,*q,*start;

struct node *createNode();
void insert_beg();
void insert_end();
void insert_at_specific();
void display();

void main(){
    int ch;
    while(1){
        printf("\n1.Create a list 2.Insert at start 3.Insert at end 4.Insert at specific 5.Display 6.Exit");
        printf("\nEnter your operation: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            createNode();
            break;

            case 2:
            insert_beg();
            break;

            case 3:
            insert_end();
            break;

            case 4:
            insert_at_specific();
            break;

            case 5:
            display();
            break;

            case 6:
            exit(0);
            break;
        }
    }
}

struct node *createNode(){
    q=(struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter the node value: ");
    scanf("%d",&x);

    q->data=x;
    q->next=NULL;
    return q;
}

void insert_beg(){
    q=createNode();
    if(q!=NULL){
        q->next=start;
        start=q;
        printf("\nNode inserted");
    }
}
void insert_end(){
    q=createNode();

    p=start;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
    printf("\nNode inserted at the end");
}

void insert_at_specific(){
    struct node * follow;
    int position,x;

    if(start==NULL){
        printf("\nList is empty! Cannot insert at specific location");
    }
    q=createNode();
    if(q!=NULL){
        printf("\nEnter the position: ");
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
            printf("%d position was not found in list",position);
            free(q);
            return;
        }
        if(p==start){
            start=q;
        }
        else{
            follow->next=q;
            q->next=p;
            printf("\nNode inserted");
        }
    }
}

void display(){
    if(start==NULL){
        printf("\nList is empty...");
    }
    p=start;
    printf("\nElements of linked list are: ");
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*p,*q,*start;

struct node *createnode();
void insert_beg();
void insert_after();
void insert_before();
void insert_end();
void insert_at_specific();
void delete_beg();
void delete_end();
// void delete_after();
void delete_at_specific();
void delete_node();
void display();
void search();
void reverse();

int main(){
    int ch;
    while(1){
        printf("\n1.Insert start 2.Insert end 3.Insert after 4.Insert at specific 5.Delete start 6.Delete end  7.Delete at specific 8.Delete node 9.Display 10.Search  11.Reverse 12.Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            insert_beg();
            break;

            case 2:
            insert_end();
            break;

            case 3:
            insert_after();
            break;

            case 4:
            insert_at_specific();
            break;

            case 5:
            delete_beg();
            break;

            case 6:
            delete_end();
            break;

            case 7:
            delete_at_specific();
            break;

            case 8:
            delete_node();
            break;

            case 9:
            display();
            break;

            case 10:
            search();
            break;

            case 11:
            reverse();
            break;

            case 12:
            exit(0);
            break;
        }

    }
}

struct node *createnode(){
    q=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the data: ");
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
        printf("\nNode inserted..");
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

void insert_after(){
    // int x;
    if(start==NULL){
        printf("\nList is empty...cannot insert after...");
    }
    q=createnode();
    int x;
    printf("\nEnter the node after which you want to insert: ");
    scanf("%d",&x);

    p=start;
    while(p!=NULL && p->data!=x){
        p=p->next;
    }
    if(p==NULL){
        printf("%d node not found ",x);
        free(q);
    }
    else{
        q->next=p->next;
        p->next=q;
        printf("\nNode inserted after...");
    }
}

void insert_before(){
    struct node *pre;
    int x;
    if(start==NULL){
        printf("\nList is empty...");
    }
    q=createnode();
    p=start;
    pre=NULL;
    printf("\nEnter the node before which you want to insert: ");
    scanf("%d",&x);
    while(p!=NULL && p->data!=x){
        pre=p;
        p=p->next;
    }
    if(p==NULL){
        printf("%d node not found",x);
    }
    else{
        pre->next=q;
        q->next=p;
        printf("\nNode inserted...");
    }
}

void insert_at_specific(){
    struct node *follow;

    int x,position;
    if(start==NULL){
        printf("\nList is empty,cannot insert at any specific position");
    }
    q=createnode();
    printf("\nEnter the position at which you want to insert: ");
    scanf("%d",&position);
    p=start;
    follow=NULL;
    x=1;

    while(x!=position){
        follow=p;
        p=p->next;
        x++;
    }
    if(p==NULL){
        printf("%d position not found ",position);
        free(q);
        return;
    }
    if(p==start){
        start=q;
    }
    else{
        follow->next=q;
        q->next=p;
        printf("\nNode inserted...");
    }
}

void delete_beg(){
    if(start==NULL){
        printf("\nList is empty");
    }
    else{
        p=start;
        printf("%d node will be deleted...",start->data);
        start=start->next;
        free(p);
        printf("\nNode deleted");
    }
}

void delete_end(){
    struct node *pre;
    if(start==NULL){
        printf("\nList is empty...");
    }
    else{
        p=start;
        while(p->next!=NULL){
            pre=p;
            p=p->next;
        }
        pre->next=NULL;
        free(p);
        printf("\nNode deleted");
    }
}

void delete_node(){
    struct node *pre;
    if(start==NULL){
        printf("\nList is empty...");
    }
    else{
        int x;
        printf("\nEnter the node you want to delete: ");
        scanf("%d",&x);

        p=start;
        pre=NULL;
        while(p->data!=x){
            pre=p;
            p=p->next;
        }
        if(p==NULL){
            printf("%d node not found",x);
        }
        pre->next=p->next;
        free(p);
        printf("\nNode deleted");
    }
}

void delete_at_specific(){
    int x,position;
    struct node *follow;
    if(start==NULL){
        printf("\nList is empty...");
    }
    printf("\nEnter the position at which you want to delete: ");
    scanf("%d",&x);

    p=start;
    follow=NULL;
    x=1;
    while(x!=position){
        follow=p;
        p=p->next;
        x++;
    }
    if(p==NULL){
        printf("%d position not found ",position);
    }
    if(p==start){
        start=p->next;
    }
    else{
        follow->next=p->next;
    }
    free(p);
    printf("Node deleted");
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

void search(){
    if(start==NULL){
        printf("\nList is empty");
    }
    else{
        p=start;
        int x;
        printf("\nEnter the search element: ");
        scanf("%d",&x);
        while(p!=NULL && p->data!=x){
            p=p->next;
        }
        if(p==NULL){
            printf("%d node not found",x);
        }
        else{
            printf("%d node present in the list ",x);
        }
    }
}

void reverse(){
    struct node*follow,*ahead;
    if(start==NULL){
        printf("\nList is empty");
    }
    p=start;
    follow=NULL;
    while(p!=NULL){
        ahead=p->next;
        p->next=follow;
        follow=p;
        p=ahead;
    }
    start=follow;
    printf("\nList reversed");
}
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
}*p,*q,*start;

struct node *createnode();
void insert_beg();
void insert_end();
void insert_after();
void insert_before();
// void insert_at_specific();
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
        printf("\n1.Insert start 2.Insert end 3.Insert after 4.Insert before 5.Insert at specific 6.Delete start 7.Delete end 8.Delete at specific 9.Delete node 10.Display 11.Search  12.Reverse 13.Exit");

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
                insert_before();
                break;

            case 5:
                // insert_at_specific();
                break;

            case 6:
                delete_beg();
                break;

            case 7:
                delete_end();
                break;

            case 8:
                delete_at_specific();
                break;

            case 9:
                delete_node();
                break;

            case 10:
                display();
                break;

            case 11:
                search();
                break;

            case 12:
                reverse();
                break;

            case 13:
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
    q->prev=NULL;
    return q;
}

void insert_beg(){
    q=createnode();
    if(q!=NULL){
        q->next=start;
        q->prev=NULL;
        if (start != NULL) {
            start->prev = q;
        }
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
    q->prev=p;
    printf("\nNode inserted");
}

void insert_after(){
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
        q->prev=p;
        if (p->next != NULL) {
            p->next->prev = q;
        }
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
        q->next=p;
        p->prev=q;
        if (pre != NULL) {
            pre->next = q;
        } else {
            start = q;
        }
        q->prev=pre;
       
        printf("\nNode inserted...");
    }
}

// void insert_at_specific(){
//     struct node *follow;

//     int x,position;
//     if(start==NULL){
//         printf("\nList is empty,cannot insert at any specific position");
//     }
//     q=createnode();
//     printf("\nEnter the position at which you want to insert: ");
//     scanf("%d",&position);
//     p=start;
//     follow=NULL;
//     x=1;

//     while(x!=position){
//         follow=p;
//         p=p->next;
//         x++;
//     }
//     if(p==NULL){
//         printf("%d position not found ",position);
//         free(q);
//         return;
//     }
//     q->next=p;
//     q->prev=follow;
//     if(p!=start){
//         follow->next=q;
//     }
//     else{
//         start=q;
//     }
//     p->prev=q;
//     printf("\nNode inserted...");
// }

void delete_beg(){
    if(start==NULL){
        printf("\nList is empty");
    }
    else{
        p=start;
        printf("%d node will be deleted...",start->data);
        start=start->next;
        if(start!=NULL){
            start->prev=NULL;
        }
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
        if(p!=NULL){
            if(p->prev!=NULL){
                p->prev->next=p->next;
            }
            else{
                start=p->next;
            }

            if(p->next!=NULL){
                p->next->prev=p->prev;
            }
            free(p);
            printf("\nNode deleted");
        }
    }
}

void delete_at_specific(){
    int x,position;
    struct node *follow;
    if(start==NULL){
        printf("\nList is empty...");
    }
    printf("\nEnter the position at which you want to delete: ");
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
    }
    if(p!=NULL){
        if(p->prev!=NULL){
            p->prev->next=p->next;
        }
        else{
            start=p->next;
        }

        if(p->next!=NULL){
            p->next->prev=p->prev;
        }
        free(p);
        printf("Node deleted");
    }
}

void delete_after() {
    if (start == NULL) {
        printf("\nList is empty...");
        return;
    }

    int x;
    printf("\nEnter the node after which you want to delete: ");
    scanf("%d", &x);

    p = start;

    while (p != NULL && p->data != x) {
        p = p->next;
    }

    if (p == NULL || p->next == NULL) {
        printf("Cannot delete after %d, node not found or it is the last node.\n", x);
        return;
    }

    q = p->next;
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prev = p;
    }

    free(q);
    printf("Node deleted after %d.\n", x);
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
    struct node*temp;
    if(start==NULL){
        printf("\nList is empty");
    }
    p=start;
    while(p!=NULL){
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
    }
    if(temp!=NULL){
        start=temp->prev;
    }
    printf("\nList reversed");
}

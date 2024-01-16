#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int rear=-1;
int front=-1;

void insert(int);
int delete();
void peek();
void show();

void main(){
    int val,ch;
    while(1){
        printf("\n1.Insert 2.Delete 3.Display 4.Peek 5.Exit");
        printf("\nEnter the operation you want to perform: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d",&val);
            insert(val);
            break;

            case 2:
            val=delete();
            printf("\nThe element deleted is %d",val);
            break;

            case 3:
            show();
            break;

            case 4:
            peek();
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("\nSelect a proper operation");
        }
    }
}

void insert(int val){
    if(rear==MAX-1){
        printf("\nOverflow...");
    }
    else{
        rear++;
        queue[rear]=val;
        if(front==-1){
            front++;
        }
    }
}

int delete(){
    int val;
    if(front==-1){
        printf("\nQueue underflow...");
    }
    else{
    val=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    return val;
    }
}

void show(){
    if(front==-1){
        printf("\nQueue underflow...");
    }
    else{
        int k=front;
        printf("\nElements of the queue are: ");
        while(k<=rear){
            printf("%d\t",queue[k]);
            k++;
        }
    }
}

void peek(){
    if(front==-1){
        printf("\nQueue underflow...");
    }
    else{
        int k=front;
        printf("The top most element from the front end is %d",queue[k]);
    }
}

//queue using LL
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
    int data;
    struct node*next;
}*front,*rear,*q;

void insert();
void delete();
void display();
void peek();

void main(){
    front=NULL;
    rear=NULL;
    int ch;
    while(1){
        printf("\n1.Insert 2.Delete 3.Display 4.Peek 5.Exit");
        printf("\nEnter the operation: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            display();
            break;

            case 4:
            peek();
            break;
            
            case 5:
            exit(0);
            break;

            default:
            printf("\nSelect a proper operation...");
        }
    }
}

void insert(){
    q=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("\nENter the value to insert: ");
    scanf("%d",&val);
    q->data=val;
    q->next=NULL;

    if(front==NULL){
        front=q;
        rear=q;
    }
    else{
        rear->next=q;
        rear=q;
    }
    printf("\nElement inserted");
}

void delete(){
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        q=front;
        front=front->next;
        q->next=NULL;
        free(q);
        if(front==NULL)
            rear=NULL;
    }
    printf("\nElement deleted");
}

void display(){
    if(front==NULL){
        printf("The queue is empty.");
    }
    else{
        printf("\nThe elements of the queue are: ");
        q=front;
        while(q!=NULL){
            printf("%d\t",q->data);
            q=q->next;
        }
    }
}

void peek(){
    if(front==NULL){
        printf("\nQueue is empty\n");
    }
    else{
        q=front;
        printf("\nThe top of the queue from the front side is %d",q->data);
    }
}

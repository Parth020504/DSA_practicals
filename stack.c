// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 100

// int stack[MAX],top=-1;

// void push();
// void pop();
// void display();
// void peek();

// int main(){
//     int ch;
//     while(1){
//     printf("\n1.Push 2.Pop 3.Display 4.Peek 5.Exit");
//     printf("\nEnter your operation: ");
//     scanf("%d",&ch);

//     switch(ch){
//         case 1:
//         push();
//         break;

//         case 2:
//         pop();
//         break;

//         case 3:
//         display();
//         break;

//         case 4:
//         peek();

//         case 5:
//         exit(0);
//         break;
//     }
// }
// }

// void push(){
//     int x;
//     if(top==MAX-1){
//         printf("\nStack overflow");
//     }
//     else{
//     printf("\nEnter the element: ");
//     scanf("%d",&x);
//     top++;
//     stack[top]=x;
//     }
// }

// void pop(){
//     if(top==-1){
//         printf("\nStack underflow");
//     }
//     else{
//         int val=stack[top];
//         top--;
//         printf("%d element deleted",val);
//     }
// }

// void display(){
//     if(top==-1){
//         printf("\nStack underflow...");
//     }
//     else{
//        int  k=0;
//         while(k<=top){
//             printf("%d\t ",stack[k]);
//             k++;
//         }
//     }
// }

// void peek(){
//     if(top==-1){
//         printf("\nStack underflow");
//     }
//     else{
//         int k=stack[top];
//         printf("\nPeek element: %d",k);
//     }
// }

// stack using a linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*top,*q;

void push();
void pop();
void display();
void peek();

void main(){
    int ch;
    while(1){
        printf("\n1.Push 2.Pop 3.Display 4.Peek");
        printf("\nEnter the operation you want to perform: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            display();
            break;

            case 4:
            peek();
            break;

        }
    }
}

void push(){
    q=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("\nEnter the element: ");
    scanf("%d",&x);
    q->data=x;
    q->next=NULL;

    if(top==NULL){
        top=q;
    }
    else{
        q->next=top;
        top=q;
    }
}

void pop(){
    if(top==NULL){
        printf("\nStack is empty...");
    }
    else{
        q=top;
        top=top->next;
        q->next=NULL;
        free(q);
        printf("\nElement popped out...");
    }
}

void display(){
    if(top==NULL){
        printf("\nStack is empty...");
    }
    else{
        q=top;
        while(q!=NULL){
            printf("%d\t",q->data);
            q=q->next;
        }
    }
}

void peek(){
    if(top==NULL){
        printf("\nStack is empty...");
    }
    else{
        q=top;
        printf("\nThe top most element of stack is %d",q->data);
    }
}

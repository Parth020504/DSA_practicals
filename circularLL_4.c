// #include<stdio.h>
// #include<conio.h>
// #include<stdlib.h>

// struct node{
//     int data;
//     struct node*next;
// }*p,*q,*start;

// struct node *createnode();
// void insert_beg();
// void insert_end();
// void delete_beg();
// void display();

// void main(){
//     int ch;
//     while(1){
//         printf("\n1.Insert at start 2.Insert at end 3.Delete first 4.Display 5.Exit");
//         printf("\nEnter your operation: ");
//         scanf("%d",&ch);

//         switch(ch){
//             case 1:
//             insert_beg();
//             break;

//             case 2:
//             insert_end();
//             break;

//             case 3:
//             delete_beg();
//             break;

//             case 4:
//             display();
//             break;

//             case 5:
//             exit(0);
//             break;
//         }
//     }
// }

// struct node *createnode(){
//     q=(struct node*)malloc(sizeof(struct node));
//     printf("Enter the data: ");
//     scanf("%d",&q->data);

//     if(start==NULL){
//         q->next=q;
//         start=q;
//     }
//     else{
//         p=start;
//         while(p->next!=start){
//             p=p->next;
//         }
//         p->next=q;
//         q->next=start;
//     }
// }

// void insert_beg(){
//     struct node *q;
//     q=createnode();
//     p=start;
//     while(p->next!=start){
//         p=p->next;
//     }
//     p->next=q;
//     q->next=start;
//     start=q;
// }

// void insert_end(){
//     struct node *q;
//     q=createnode();
//     p=start;
//     while(p->next!=start){
//         p=p->next;
//     }
//     p->next=q;
//     q->next=start;
// }

// void delete_beg(){
//     p=start;
//     while(p->next!=start){
//         p=p->next;
//     }
//     p->next=start->next;
//     free(start);
//     start=p->next;
// }

// void display(){
//     if(q==NULL){
//         printf("\nList is empty...");
//     }
//     else{
//         p=start;
//         while(p->next!=start){
//             printf("%d\t",p->data);
//             p=p->next;
//         }
//     }
//     printf("%d\t",p->data);
// }

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*p,*q,*start;

struct node *createnode();
void insert_beg();
void insert_end();
void delete_beg();
void display();

void check();

void main(){
    int ch;
    while(1){
        printf("\n1.Insert at start 2.Insert at end 3.Delete first 4.Display 5.Check 6.Exit");
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
            delete_beg();
            break;

            case 4:
            display();
            break;

            case 5:
            check();
            break;

            case 6:
            exit(0);
            break;
        }
    }
}

struct node *createnode(){
    q=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d",&q->data);

    if(start==NULL){
        q->next=q;
        start=q;
    }
    else{
        p=start;
        while(p->next!=start){
            p=p->next;
        }
        p->next=q;
        q->next=start; 
    }
}

void insert_beg(){
    q=createnode();
    p=start;
    while(p->next!=start){
        p=p->next;
    }
    p->next=q;
    q->next=start;
    start=q;
}

void insert_end(){
    q=createnode();
    p=start;
    while(p->next!=start){
        p=p->next;
    }
    p->next=q;
    q->next=start;
}

void delete_beg(){
    if(start==NULL){
        printf("\nList is empty...");
    }
    p=start;
    while(p->next!=start){
        p=p->next;
    }
    p->next=start->next;
    free(start);
    start=p->next;
    printf("\nNode deleted");
}

void display(){
    if(q == NULL) {
        printf("The list is empty.\n");
    }
    p=start;
    while(p->next!=start){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d \t",p->data);
}

void check() {
    int position;
    if (start == NULL) {
        printf("\nList is empty...");
        return;
    }

    printf("\nEnter the position to check: ");
    scanf("%d", &position);

    p = start;
    int current_position = 1;

    do {
        if (current_position == position) {
            printf("Element at position %d: %d\n", position, p->data);
            return;
        }
        p = p->next;
        current_position++;
    } while (p != start);

    printf("Position %d is out of bounds.\n", position);
}

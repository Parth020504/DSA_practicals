#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

struct node{
    int coeff;
    struct node*next;
    int exponent;
};

struct node *create(int coeff,int exponent){
    struct node* newTerm=(struct node *)malloc(sizeof(struct node));
    if(newTerm==NULL){
        printf("\nMemory allocation failed");
    }
    newTerm->coeff=coeff;
    newTerm->exponent=exponent;
    newTerm->next=NULL;
    return newTerm;
}

void insert(struct node **poly,int coeff,int exponent){
    struct node *newTerm=create(coeff,exponent);
    if(*poly==NULL){
        *poly=newTerm;
    }
    else{
        struct node* current=*poly;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newTerm;
    }
}

void display(struct node *poly){
    while(poly!=NULL){
        printf("%dx^%d ",poly->coeff,poly->exponent);
        if(poly->next!=NULL){
            printf("+");
        }
        poly=poly->next;
    }
}

int main(){
    struct node *polynomial=NULL;
    insert(&polynomial,3,2);
    insert(&polynomial,-4,1);
    insert(&polynomial,2,0);

    printf("\nPolynomial: ");
    display(polynomial);
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 100

int stack[MAX];
int top=-1;

void push(int item){
    if(top==MAX-1){
        printf("\nStack overflow");
    }
    else{
        top++;
        stack[top]=item;
    }
}

int pop(){
    int item;
    if(top==-1){
        printf("\nStack undeflow");
    }
    else{
        item=stack[top];
        top--;
        return item;
    }
}

int is_op(char symbol){
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/'){
        return 1;
    }
    return 0;
}

int evaluate(char *expression){
    int op1,op2,result;
    int i=0;
    char symbol=expression[i];

    while(symbol !='\0'){
        if(isdigit(symbol)){
            int num=symbol-'0';
            push(num);
        }
        else if(is_op(symbol)){
            op2=pop();
            op1=pop();
            switch(symbol){
                case '+':
                result=op1+op2;
                break;

                case '-':
                result=op1-op2;
                break;

                case '*':
                result=op1*op2;
                break;

                case '/':
                result=op1/op2;
                break;
            }
            push(result);
        }
        i++;
        symbol=expression[i];
    }
    result=pop();
    return result;
}

int main(){
    char expression[50];

    printf("\nEnter the postfix expression: ");
    gets(expression);

    int final=evaluate(expression);
    printf("\nThe result is %d",final);
}
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100

int stack[MAX];
int top=-1;

void push(int item){
    if(top==MAX-1){
        printf("\nStack overflow...");
    }
    else{
        top++;
        stack[top]=item;
    }
}

int pop(){
    int item;
    if(top==-1){
        printf("\nStack underflow...");
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
    // char symbol=expression[i];

    int length=strlen(expression);

    for(int i=length-1;i>=0;i--){
        if(isdigit(expression[i])){
            int num=0;
            while(i>=0 && isdigit(expression[i])){
                num=num*10+(expression[i]-'0');
                i--;
            }
            i++;
            push(num);
        }
        else if(is_op(expression[i])){
            op1=pop();
            op2=pop();
            switch(expression[i]){
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
    }
    return stack[top];
}
int main(){
    char expression[50];
    printf("\nEnter the prefix expression: ");
    gets(expression);

    int result=evaluate(expression);
    printf("\nThe final result is %d",result);
    return 0;
}
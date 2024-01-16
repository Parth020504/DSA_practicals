#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int precedence(char operator){
    switch(operator){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
        return -1; // for invalid operatorsreturn -1;
    }
}

int is_op(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    return 0;
}

char *convert_to_postfix(char *infix){
    int i,j;
    int len=strlen(infix);
    char stack[MAX];
    int top=-1;
    char *postfix=(char *)malloc(sizeof(char) * (len+2));

    for(i=0, j=0;i<len;i++){
        if(infix[i]==' ' || infix[i]=='\t'){
            continue;
        }

        if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='('){
            stack[++top]=infix[i];
        }
        else if(infix[i]==')'){
            while(top>-1 && stack[top]!='('){
                postfix[j++]=stack[top--];
                
            }
            top--;
        }
        else if(is_op(infix[i])){
            while(top>-1 && precedence(stack[top]) >= precedence(infix[i])){
                postfix[j++]=stack[top--];
            }
            stack[++top]=infix[i];
        }
    }

   while(top > -1){
    if(stack[top] == '('){
        printf("Invalid expression\n");
        free(postfix);  // Free the allocated memory before returning
        return NULL;
    }
    postfix[j++] = stack[top--];
}
    postfix[j]='\0';
    return postfix;
}

int main(){
    char infix[MAX]="a+b*(c^d-e)^(f+g*h)-i";

    char *postfix=convert_to_postfix(infix);
    printf("%s\n",postfix);
    return 0;
}
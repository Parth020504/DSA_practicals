#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *s){
    char *stack[100];
    int top=-1;

    char temp[100];
    int tempIndex=0;

    for(int i=0;s[i]!='\0'; i++){
        if(s[i]==' '){
            temp[tempIndex]='\0';
            stack[++top]=strdup(temp);
            tempIndex=0;
        }
        else{
            temp[tempIndex++]=s[i];
        }
    }
    //for the last word in the string

    temp[tempIndex]='\0';
    stack[++top]=strdup(temp);

    while(top!=-1){
        printf("%s \t",stack[top--]);
    }
}

int main(){
    char string[50];
    printf("\nEnter the string: ");
    gets(string);
    printf("\n");
    printf("\nThe reversed sentence is :");
    printf("\n");
    reverse(string);
    return 0;
}
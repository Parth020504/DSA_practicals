#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return -1; // for invalid operators
    }
}

int is_op(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

void reverseString(char *str) {
    int length = strlen(str);
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char *convert_to_prefix(char *infix) {
    int i, j;
    int len = strlen(infix);
    char stack[MAX];
    int top = -1;
    char *prefix = (char *)malloc(sizeof(char) * (len + 2));

    for (i = len - 1, j = 0; i >= 0; i--) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            continue;
        }

        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } 
        else if (infix[i] == ')') {
            stack[++top] = infix[i];
        } 
        else if (infix[i] == '(') {
            while (top > -1 && stack[top] != ')') {
                prefix[j++] = stack[top--];
            }
            top--;
        } 
        else if (is_op(infix[i])) {
            while (top > -1 && precedence(stack[top]) > precedence(infix[i])) {
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while (top > -1) {
        if (stack[top] == ')') {
            printf("Invalid expression\n");
            free(prefix); // Free the allocated memory before returning
            return NULL;
        }
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';
    reverseString(prefix);
    return prefix;
}

int main() {
    char infix[MAX] = "a+b*(c^d-e)^(f+g*h)-i";

    char *prefix = convert_to_prefix(infix);
    printf("%s\n", prefix);
    free(prefix);
    return 0;
}

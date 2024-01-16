#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int rear = -1;
int front = -1;

void insert(int);
int delete();
void peek();
void show();

int main() {
    int val, ch;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Peek 5.Exit");
        printf("\nEnter the operation you want to perform: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("\nEnter the data to be inserted: ");
            scanf("%d", &val);
            insert(val);
            break;

        case 2:
            val = delete();
            if (val != -1) {
                printf("\nThe element deleted is %d", val);
            }
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
    return 0;
}

void insert(int val) {
    if (front == 0 && rear == MAX - 1) {
        printf("\nQueue overflow...");
    } else if (front != 0 && rear == MAX - 1) {
        rear = 0;
        queue[rear] = val;
    } else {
        rear++;
        queue[rear] = val;
    }
}

int delete() {
    int val;
    if (front == -1 && rear == -1) {
        printf("\nQueue underflow...");
        return -1; // Return a sentinel value to indicate underflow
    }
    val = queue[front];
    if (front == rear) {
        front = rear = -1;
    } 
    else {
        if (front == MAX - 1) {
            front = 0;
        } 
        else {
            front++;
        }
    }
    return val;
}

void peek() {
    if (front == -1) {
        printf("\nQueue underflow");
    } else {
        int k = front;
        printf("\nThe peek of queue is %d", queue[k]);
    }
}

void show() {
    if (front == -1 && rear == -1) {
        printf("\nQueue underflow");
    } 
    else {
        if (front <= rear) {
            for (int i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        } 
        else {
            for (int i = front; i < MAX; i++)
                printf("%d ", queue[i]);

            for (int i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
    }
}

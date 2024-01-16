#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]> arr[largest]){
        largest=left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest=right;
    }
    if(largest != i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildHeap(int arr[],int n){
    int startIndex=(n/2)-1;

    for(int i=startIndex;i>=0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    buildHeap(arr,n);

    for(int i=n-1;i>0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}

int main(){
    int choice,n,arr[MAX];

    printf("\nEnter the length of the array: ");
    scanf("%d",&n);

    printf("\nEnter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    do{
        printf("\n1.Heap Sort 2.Display sorted array 3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            heapSort(arr,n);
            printf("\nArray sorted using heap sort");
            break;

            case 2:
            display(arr,n);
            break;

            case 3:
            exit(0);
            break;
        }
    }while(1);
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void swap(int *a,int *b);
int partition(int arr[],int low,int high);
void quicksort(int arr[],int low,int high);
void insertion(int arr[],int n);
void display(int arr[],int size);

int main(){
    int choice,size;

    printf("\nEnter the size of the array: ");
    scanf("%d",&size);

    int arr[size];

    printf("\nEnter the elements of the array: ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }

    do{
        printf("\n1.Quick Sort 2.Insertion Sort 3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            quicksort(arr,0,size-1);
            display(arr,size);
            break;

            case 2:
            insertion(arr,size);
            display(arr,size);

            case 3:
            exit(0);
            break;

        }
    }while(1);
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low - 1);

    for(int j=low;j<=high-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}

void insertion(int arr[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;

        while(temp<arr[j] && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
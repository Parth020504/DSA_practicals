#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int low,int high){
    int pivot=arr[high];
    int i=(low-1);

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
    printf("\nElements of the array are: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[]={12,11,6,3,5};
    int size=sizeof(arr) / sizeof(arr[0]);

    printf("\nOriginal Array: ");
    display(arr,size);

    quicksort(arr,0,size-1);
    printf("\nSorted array: ");
    display(arr,size);

    return 0;
}
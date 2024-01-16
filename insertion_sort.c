#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void insertion(int arr[],int n);

void main(){
    int arr[10],i,n;
    printf("\nEnter the size of the array: ");
    scanf("%d",&n);

    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    insertion(arr,n);
    printf("\nThe sorted array after insertion sort is ");
    for(i=0;i<n;i++){
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
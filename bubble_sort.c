#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(){
    int arr[10],i,j,temp,n;

    printf("\nEnter the length of the array: ");
    scanf("%d",&n);

    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nThe sorted array after bubble sort: ");
    for(i=0;i<n;i++){
        printf("%d \t",arr[i]);
    }
}
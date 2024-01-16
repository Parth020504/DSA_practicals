#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int smallest(int arr[],int k,int n);

void selection(int arr[],int n);

void main(){
    int arr[10],n,i;

    printf("\nEnter the length of the array: ");
    scanf("%d",&n);

    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection(arr,n);
    printf("\nThe sorted array is :");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
int smallest(int arr[],int k,int n){
    int pos=k,small=arr[k],i;
    for(i=k+1;i<n;i++){
        if(arr[i]<small){
            small=arr[i];
            pos=i;
        }
    }
    return pos;
}

void selection(int arr[],int n){
    int k,pos,temp;
    for(k=0;k<n;k++){
        pos=smallest(arr,k,n);
        temp=arr[k];
        arr[k]=arr[pos];
        arr[pos]=temp;
    }
}


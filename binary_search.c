#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10],n,num,i,l,m,h;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);

    printf("\nEnter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the element you want to search: ");
    scanf("%d",&num);

    l=0;
    h=n-1;
    m=(l+h)/2;

    while(num!=arr[m] && l<m){
        if(num>arr[m]){
            l=m+1;
        }
        else{
            h=m-1;
        }
        m=(l+h)/2;
    }
    if(num==arr[m]){
        printf("\nElement %d found at position %d",num,m+1);
    }
    else{
        printf("\nElement %d not found in the array ",num);
    }
}
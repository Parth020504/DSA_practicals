#include<stdio.h>
#include<stdlib.h>

int min(int x, int y){
    return (x<=y)?x:y;
}

int fibonacci(int arr[],int n,int target){
    int m2=0;
    int m1=1;
    int m=m2+m1;

    while(m<n){
        m2=m1;
        m1=m;
        m=m2+m1;
    }
    int offset=-1;

    while(m>1){
        int i=min(offset+m2, n-1);

        if(arr[i] < target){
            m=m1;
            m1=m2;
            m2=m-m1;
            offset=i;
        }
        else if(arr[i]>target){
            m=m2;
            m1=m1-m2;
            m2=m-m1;
        }
        else{
            return i;
        }
    }
    if(m1 && arr[offset+1]==target){
        return (offset+1);
    }
    else{
        return -1;
    }
}

int main(){
    int arr[5],n,i,target;

    printf("\nEnter length of the array: ");
    scanf("%d",&n);

    printf("\nEnter the elements of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the target: ");
    scanf("%d",&target);

    int result=fibonacci(arr,n,target);
    if(result!=-1){
        printf("\nElement %d found at index %d ",target,result);
    }
    else{
        printf("\nElement %d not found ",target);
    }
}
#include<stdio.h>

void findIndices(int arr[], int size, int target){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]+arr[j]==target){
                printf("The two elements which add upto 9 are %d and %d \n their indexes are %d and %d",arr[i],arr[j],i,j);
                return;
            }
            else{
                printf("\nNo such elements found in the array whose sum add upto 9");
            }
        }
    }
}

int main(){
    int arr[]={2,7,8,10,6,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=9;

    findIndices(arr,size,target);
    return 0;
}
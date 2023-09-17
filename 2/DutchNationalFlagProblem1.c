#include<stdio.h>

 void partitionArray(int* arr,size_t length,int num){
    int l=0,r=0;
    int temp;
    for(;r<length;r++){
        if(arr[r]<=num){
            temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            l++;
        }
    }
    return;
 }

int main(){
    int arr[]={2,9,7,8,6,3,4,5,2};
    size_t length=sizeof(arr)/sizeof(arr[0]);
    partitionArray(arr,length,4);
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
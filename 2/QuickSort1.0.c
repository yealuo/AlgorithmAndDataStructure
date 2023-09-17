#include<stdio.h>

void quickSort1(int* arr,int L,int R){
    if(L>=R){
        return;
    }
    int l=L,r=L,temp;
    for(;r<R;r++){
        if(arr[r]<=arr[R]){
            temp=arr[l];
            arr[l]=arr[r];
            arr[r]=temp;
            l++;
        }
    }
    temp=arr[l];
    arr[l]=arr[R];
    arr[R]=temp;
    quickSort1(arr,L,l-1);
    quickSort1(arr,l+1,R);
    return;
}

int main(){
    int arr[]={9,3,5,6,14,68,52,34,15};
    size_t length=sizeof(arr)/sizeof(arr[0]);
    quickSort1(arr,0,length-1);
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
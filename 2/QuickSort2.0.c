#include<stdio.h>

void quickSort2(int* arr,int L,int R){
    if(L>=R){
        return;
    }
    int l=L,r=R-1,i=L,temp;
    while(i<=r){
        if(arr[i]<arr[R]){
            temp=arr[l];
            arr[l]=arr[i];
            arr[i]=temp;
            i++;
            l++;
        }else if(arr[i]==arr[R]){
            i++;
        }else{
            temp=arr[r];
            arr[r]=arr[i];
            arr[i]=temp;
            r--;
        }
    }
    temp=arr[i];
    arr[i]=arr[R];
    arr[R]=temp;
    quickSort2(arr,L,l-1);
    quickSort2(arr,i+1,R);
    return;
}

int main(){
    int arr[]={9,3,5,6,14,68,52,34,15};
    size_t length=sizeof(arr)/sizeof(arr[0]);
    quickSort2(arr,0,length-1);
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
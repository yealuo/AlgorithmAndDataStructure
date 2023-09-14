#include<stdio.h>

//求arr[L...R]范围上的最大值
int process(int arr[],int L,int R){
    if(L==R){
        return arr[L];
    }
    int mid=L+((R-L)>>1);
    int leftMax=process(arr,L,mid);
    int rightMax=process(arr,mid+1,R);
    return leftMax>rightMax?leftMax:rightMax;
}

int main(){
    int arr[]={1,3,4,18,9,6,8,7,13,18,15};
    int result=process(arr,0,10);
    printf("%d",result);
    return 0;
}
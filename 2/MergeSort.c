#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int L,int R,int M);
//递归
void process(int arr[],int L,int R){
    if(L==R){
        return;
    }
    int mid=L+((R-L)>>1);
    process(arr,L,mid);
    process(arr,mid+1,R);
    merge(arr,L,R,mid);
}

//归并
void merge(int arr[],int L,int R,int M){
    int* help=(int*)malloc((R-L+1)*sizeof(int));
    int i=0;
    int p1=L,p2=M+1;
    while(p1<=M && p2<=R){
        help[i++]=arr[p1]<=arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=M){
        help[i++]=arr[p1++];
    }
    while(p2<=R){
        help[i++]=arr[p2++];
    }
    for(int j=0;j<(R-L+1);j++){
        arr[L+j]=help[j];
    }
    free(help);
    return;
}

int main(){
    int arr[]={9,3,5,6,14,68,52,34,15};
    size_t length=sizeof(arr)/sizeof(arr[0]);
    process(arr,0,length-1);
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
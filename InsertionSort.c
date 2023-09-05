#include<stdio.h>

void InsertionSort(int* arr,int length){
    if(arr==NULL||length<2)
        return;
    for(int i=1;i<length;i++){
        for(int j=i-1;j>=0 && arr[j]>arr[j+1];j--){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){
    int array[]={9,3,8,10,6,2,1,5,4,7,312,253,332};
    int length=sizeof(array)/sizeof(array[0]);
    InsertionSort(array,length);
    for(int i=0;i<length;i++)
        printf("%d\n",array[i]);
    return 0;
}
#include<stdio.h>


void BubbleSort(int* arr,int length){
    if(arr==NULL||length<2)
        return;
    for(int i=length-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}


int main(){
    int array[]={9,3,8,10,6,2,1,5,4,7,192,168};
    int length=sizeof(array)/sizeof(array[0]);
    BubbleSort(array,length);
    for(int i=0;i<length;i++)
        printf("%d\n",array[i]);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

// 归并并计算逆序对
int merge(int arr[], int L, int R, int M) {
    int* help = (int*)malloc((R - L + 1) * sizeof(int));
    int i = 0,result=0;
    int p1 = L, p2 = M + 1;
    while (p1 <= M && p2 <= R) {
        if (arr[p1] > arr[p2]) {
            help[i] = arr[p1];
            result+=(R-p2+1);
            i++;
            p1++;
        } else {
            help[i++] = arr[p2++];
        }
    }
    while (p1 <= M) {
        help[i++] = arr[p1++];
    }
    while (p2 <= R) {
        help[i++] = arr[p2++];
    }
    for (int j = 0; j < (R - L + 1); j++) {
        arr[L + j] = help[j];
    }
    free(help);
    return result;
}


int process(int arr[], int L, int R) {
    if (L == R) {
        return 0;
    }
    int mid = L + ((R - L) >> 1);
    return process(arr, L, mid)+process(arr, mid + 1, R)+merge(arr, L, R, mid);
}

int reversePairs(int* nums, int numsSize){
    int L=0,R=numsSize-1;
    printf("%d",process(nums,L,R));
    return 0;
}


int main(){
    int arr[] = {7,5,6,4};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    reversePairs(arr,length);
    return 0;
}
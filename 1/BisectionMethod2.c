#include <stdio.h>

void bisection2(int* arr, size_t length, int target) {
    int left = 0, right = length - 1,t=-1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (arr[mid] >= target) {
            t=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    if(t<0)
        printf("未找到，该数不在此数组。");
    else
        printf("已找到，≥%d最左侧位置索引值为：%d",target,t);
}

int main() {
    int array[] = {1, 3, 7, 9, 10, 16, 23, 33, 36, 38, 40, 42, 49, 56, 57, 59};
    int length = sizeof(array) / sizeof(array[0]);
    bisection2(array, length, 16);
    return 0;
}
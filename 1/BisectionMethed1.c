#include <stdio.h>

// 在一个有序数组中，找某个数是否存在
void bisection1(int* arr, size_t length, int target) {
    int left = 0, right = length - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (arr[mid] == target) {
            printf("已找到，该数的索引值为：%d", mid);
            return;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        }
    }
    printf("未找到，该数不在此数组。");
    return;
}

int main() {
    int array[] = {1, 3, 7, 9, 10, 16, 23, 33, 36, 38, 40, 42, 49, 56, 57, 59};
    size_t length = sizeof(array) / sizeof(array[0]);
    bisection1(array, length, 57);
    return 0;
}
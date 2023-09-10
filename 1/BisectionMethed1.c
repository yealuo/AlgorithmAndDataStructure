#include <stdio.h>

void bisection(int* arr, int length, int target) {
    int left = 0, right = length - 1;
    while (1) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            printf("已找到，该数的索引值为：%d", mid);
            break;
        } else if (arr[mid] > target) {
            right = mid - 1;
            if (left > right) {
                printf("未找到，该数不在此数组。");
                break;
            }
        } else if (arr[mid] < target) {
            left = mid + 1;
            if (left > right) {
                printf("未找到，该数不在此数组。");
                break;
            }
        }
    }
}

int main() {
    int array[] = {1,  3,  7,  9,  10, 16, 23, 33, 36,
                   38, 40, 42, 49, 56, 57, 59, 70};
    int length = sizeof(array) / sizeof(array[0]);
    bisection(array, length, 58);
    return 0;
}
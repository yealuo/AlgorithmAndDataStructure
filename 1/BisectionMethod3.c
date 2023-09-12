#include <stdio.h>

// 在一个无序数组中(相邻两数不相等)找到一个局部最小值（比左、右都小）
void bisection3(int* arr, size_t length) {
    int left = 0, right = length - 1, mid;
    if (arr[0] < arr[1]) {
        printf("已找到，局部最小值为：%d，索引值为：%d", arr[0], 0);
        return;
    } else if (arr[length - 1] < arr[length - 2]) {
        printf("已找到，局部最小值为：%d，索引值为：%d", arr[length - 1],
               length - 1);
        return;
    } else {
        while (1) {
            mid = (left + right) >> 1;
            if (arr[mid] < arr[mid - 1] && arr[mid] < arr[mid + 1]) {
                printf("已找到，局部最小值为：%d，索引值为：%d", arr[mid], mid);
                return;
            } else if (arr[mid] > arr[mid - 1]) {
                right = mid;
            } else if (arr[mid] > arr[mid + 1]) {
                left = mid;
            }
        }
    }
}

int main() {
    int array[] = {8, 4, 5, 7, 0, 13, 1, 16, 17, 15, 19, 21, 29, 37};
    size_t length = sizeof(array) / sizeof(array[0]);
    bisection3(array, length);
    return 0;
}
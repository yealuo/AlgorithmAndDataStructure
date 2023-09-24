#include <stdio.h>
#include <stdlib.h>

// 获取最大值的位数
int maxBits(int* arr, size_t length) {
    if (arr == NULL || length == 0) {
        return 0;
    }
    int max = arr[0];
    for (int i = 1; i < length; i++) {
        max = arr[i] > max ? arr[i] : max;
    }
    int res = 0;
    while (max != 0) {
        max /= 10;
        res++;
    }
    return res;
}

// 返回指定位上的数字
int getDigit(int number, int d) {
    for (int i = 1; i < d; i++) {
        number /= 10;
    }
    return number % 10;
}

// 基数排序
void radixSort(int* arr, int L, int R, int maxBits) {
    const int radix = 10;
    // 有多少个数准备多少个辅助空间
    int* bucket = (int*)malloc((R - L + 1) * sizeof(int));
    if (bucket == NULL) {
        // 处理内存分配失败的情况
        exit(1);
    }
    for (int i = 1; i <= maxBits; i++) {
        // 数组最大值有几位就进出桶多少次
        // 基数计数
        int count[radix] = {0};
        for (int j = L; j <= R; j++) {
            int digit = getDigit(arr[j], i);
            count[digit]++;
        }

        for (int j = 1; j < radix; j++) {
            // 将count更新为前缀和数组
            count[j] += count[j - 1];
        }
        for (int j = R; j >= L; j--) {
            // 从右往左对当前位进行桶排序
            int digit = getDigit(arr[j], i);
            bucket[count[digit] - 1] = arr[j];
            count[digit]--;
        }
        for (int j = 0, k = L; k <= R; j++, k++) {
            arr[k] = bucket[j];
        }
    }
    free(bucket);
    return;
}

int main() {
    int arr[] = {1, 3, 5, 6, 0, 15, 32, 26, 9, 8, 6, 4};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, 0, length - 1, maxBits(arr, length));
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
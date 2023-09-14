#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 随机样本产生器
int* generateRandomArray(size_t maxSize, size_t maxValue, size_t* length) {
    srand(time(NULL));
    *length = rand() % maxSize + 1;
    int* arr = (int*)malloc((*length) * sizeof(int));
    for (int i = 0; i < (*length); i++) {
        arr[i] = rand() % (2 * maxValue + 1) - maxValue;
    }
    return arr;
}

// 判断两数组是否相等
bool isEqual(int arr1[], int arr2[], size_t length) {
    for (int i = 0; i < length; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}

void SelectionSort(int* arr, int length) {
    if (arr == NULL || length < 2)
        return;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void BubbleSort(int* arr, int length) {
    if (arr == NULL || length < 2)
        return;
    for (int i = length - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void InsertionSort(int* arr, int length) {
    if (arr == NULL || length < 2)
        return;
    for (int i = 1; i < length; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    size_t testTime = 500000;
    size_t maxSize = 100;
    size_t maxValue = 100;
    bool isSuccess = true;
    size_t length;
    for (int i = 0; i < testTime; i++) {
        int* arr1 = generateRandomArray(maxSize, maxValue, &length);
        int* arr2 = (int*)malloc(length * sizeof(int));
        memcpy(arr2, arr1, length * sizeof(int));
        BubbleSort(arr1, length);
        InsertionSort(arr2, length);
        if (!isEqual(arr1, arr2, length)) {
            printf("arr1：");
            for (int i = 0; i < length; i++) {
                printf("%d ", arr1[i]);
                if (i == length - 1) {
                    printf("\n");
                }
            }
            printf("arr2：");
            for (int j = 0; j < length; j++) {
                printf("%d ", arr2[j]);
                if (j == length - 1) {
                    printf("\n");
                }
            }
            isSuccess = false;
            break;
        }
    }
    printf(isSuccess ? "Conrrect!" : "Error!");
    return 0;
}
#include <stdio.h>

// 交换
void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

// index的数向上检查
void heapInsert(int* arr, int index) {
    while (arr[index] > arr[(index - 1) >> 1]) {
        swap(arr, index, (index - 1) >> 1);
        index = (index - 1) >> 1;
    }
    return;
}

// index的数向下检查
void heapify(int* arr, int index, int heapSize) {
    int left = index * 2 + 1;
    int largest;
    while (left < heapSize) {
        if (left + 1 < heapSize && arr[left + 1] > arr[left]) {
            largest = left + 1;
        } else {
            largest = left;
        }
        largest = arr[index] > arr[largest] ? index : largest;
        if (largest == index) {
            break;
        }
        swap(arr, largest, index);
        index = largest;
        left = index * 2 + 1;
    }
    return;
}

void heapSort(int* arr, size_t length) {
    if (arr == NULL || length < 2) {
        return;
    }
    for (int i = 0; i < length; i++) {
        heapInsert(arr, i);
    }
    int heapSize = length;
    while (heapSize > 1) {
        swap(arr, 0, heapSize - 1);
        heapify(arr, 0, heapSize - 1);
        heapSize--;
    }
    return;
}

int main() {
    int arr[] = {2, 5, 1, 3, 4, 9, 8, 13, 56, 35, 21};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
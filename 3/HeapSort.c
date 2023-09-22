#include "HeapSort.h"
#include <stdio.h>

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
    int arr[] = {2, 5, 3, 4, 9, 8, 13, 56, 35, 21};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, length);
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
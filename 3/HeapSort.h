#ifndef HEAPSORT_H
#define HEAPSORT_H

void swap(int* arr, int index1, int index2);
void heapInsert(int* arr, int index);
void heapify(int* arr, int index, int heapSize);

//交换
void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return;
}

//index的数向上检查
void heapInsert(int* arr, int index) {
    while (arr[index] > arr[(index - 1) >> 1]) {
        swap(arr, index, (index - 1) >> 1);
        index = (index - 1) >> 1;
    }
    return;
}

//index的数向下检查
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

#endif
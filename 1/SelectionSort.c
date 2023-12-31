#include <stdio.h>

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

int main() {
    int array[] = {9, 3, 8, 10, 6, 2, 1, 5, 4, 7, 312, 253, 332};
    int length = sizeof(array) / sizeof(array[0]);
    SelectionSort(array, length);
    for (int i = 0; i < length; i++)
        printf("%d\n", array[i]);
    return 0;
}
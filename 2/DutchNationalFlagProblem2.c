#include <stdio.h>

void partitionArray(int* arr, size_t length, int num) {
    int l = 0, r = length - 1, i = 0;
    int temp;
    while (i <= r) {
        if (arr[i] < num) {
            temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
            i++;
            l++;
        } else if (arr[i] == num) {
            i++;
        } else {
            temp = arr[r];
            arr[r] = arr[i];
            arr[i] = temp;
            r--;
        }
    }
    return;
}

int main() {
    int arr[] = {2, 9, 7, 8, 6, 3, 4, 5, 2, 4, 4, 4};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    partitionArray(arr, length, 4);
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h>

int length(int* arr) {
    return sizeof(arr) / sizeof(arr[0]);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    printf("%d", length(arr));
    printf("\n%d", sizeof(arr) / sizeof(arr[0]));
}
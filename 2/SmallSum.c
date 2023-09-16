#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int L, int R, int M, int* smallSum);
// 递归
void process(int arr[], int L, int R, int* smallSum) {
    if (L == R) {
        return;
    }
    int mid = L + ((R - L) >> 1);
    process(arr, L, mid, smallSum);
    process(arr, mid + 1, R, smallSum);
    merge(arr, L, R, mid, smallSum);
}

// 归并并计算小和
void merge(int arr[], int L, int R, int M, int* smallSum) {
    int* help = (int*)malloc((R - L + 1) * sizeof(int));
    int i = 0;
    int p1 = L, p2 = M + 1;
    while (p1 <= M && p2 <= R) {
        if (arr[p1] < arr[p2]) {
            help[i] = arr[p1];
            *smallSum += (R - p2 + 1) * arr[p1];
            i++;
            p1++;
        } else {
            help[i++] = arr[p2++];
        }
    }
    while (p1 <= M) {
        help[i++] = arr[p1++];
    }
    while (p2 <= R) {
        help[i++] = arr[p2++];
    }
    for (int j = 0; j < (R - L + 1); j++) {
        arr[L + j] = help[j];
    }
    free(help);
    return;
}

int main() {
    int smallSum = 0;
    int arr[] = {1, 3, 4, 2, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    process(arr, 0, length - 1, &smallSum);
    printf("\n%d", smallSum);
    return 0;
}
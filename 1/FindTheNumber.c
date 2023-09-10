#include <stdio.h>

// 找出出现了奇数次的那个数
int find_one_num(int arr[], int length) {
    int result = 0;
    for (int i = 0; i < length; i++)
        result ^= arr[i];
    return result;
}

// 找出出现了奇数次的那两个数
int find_two_num(int arr[], int length, int* first_num, int* second_num) {
    int ero = 0;
    for (int i = 0; i < length; i++)
        ero ^= arr[i];
    int right_one = ero & (~ero + 1);
    *first_num = *second_num = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] & right_one != 0)
            *first_num ^= arr[i];
    }
    *second_num = *first_num ^ ero;
}

int main() {
    int array1[] = {1, 1, 2, 2, 5, 3, 5, 3, 3, 6, 3, 9, 9, 7, 7};  // 6
    int length1 = sizeof(array1) / sizeof(array1[0]);
    printf("%d", find_one_num(array1, length1));

    int array2[] = {1, 1, 2, 2, 5, 3, 5, 3, 6, 3, 9, 9, 7, 7};  // 3,6
    int length2 = sizeof(array2) / sizeof(array2[0]);
    int result1, result2;
    find_two_num(array2, length2, &result1, &result2);
    printf("\n%d  %d", result1, result2);
    return 0;
}
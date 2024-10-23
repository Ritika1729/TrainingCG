#include <stdio.h>

#define MAX_SIZE 100 

int main() {
    int size1, size2;
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE], filtered[MAX_SIZE];
    int merged_size, filtered_size;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    if (size1 <= 0 || size1 > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size1; ++i) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    if (size2 <= 0 || size2 > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size2; ++i) {
        scanf("%d", &arr2[i]);
    }

    merged_size = size1 + size2;
    for (int i = 0; i < size1; ++i) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) {
        merged[size1 + i] = arr2[i];
    }

    filtered_size = 0;
    for (int i = 0; i < merged_size; ++i) {
        if (merged[i] % 2 != 0) {
            filtered[filtered_size++] = merged[i];
        }
    }

    for (int i = 0; i < filtered_size - 1; ++i) {
        for (int j = 0; j < filtered_size - i - 1; ++j) {
            if (filtered[j] > filtered[j + 1]) {
                int temp = filtered[j];
                filtered[j] = filtered[j + 1];
                filtered[j + 1] = temp;
            }
        }
    }

    printf("Final sorted array with odd numbers only:\n");
    for (int i = 0; i < filtered_size; ++i) {
        printf("%d ", filtered[i]);
    }
    printf("\n");

    return 0;
}


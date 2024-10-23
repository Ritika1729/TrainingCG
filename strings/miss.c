#include <stdio.h>

#define MAX_SIZE 100

int find_missing_number(int arr[], int size) {
    int n = size + 1; 
    int expected_sum = n * (n + 1) / 2; 
    int actual_sum = 0;

    for (int i = 0; i < size; ++i) {
        actual_sum += arr[i];
    }

    return expected_sum - actual_sum;
}

int main() {
    int n;
    int arr[MAX_SIZE]; 
    printf("Enter the number of elements (excluding the missing number): ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX_SIZE) {
        printf("Invalid number of elements. It should be between 1 and %d.\n", MAX_SIZE - 1);
        return 1;
    }
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int missing_number = find_missing_number(arr, n);
    printf("The missing number is: %d\n", missing_number);

    return 0;
}


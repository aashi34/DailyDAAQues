/*Question No. 26

Study and implement the Dutch National Flag Algorithm. Identify 2-3 case studies where it is applicable.
Problem:
Given an array containing only 0s, 1s, and 2s, sort the array without using any built-in sorting function.

Case Studies:
1. Sorting colors (Red, White, Blue).
2. Partitioning data into three priority levels.
3. Three-way partitioning in Quick Sort.
*/

#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Dutch National Flag Algorithm
void dutchNationalFlag(int arr[], int n) {

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {

        if (arr[mid] == 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }

        else if (arr[mid] == 1) {
            mid++;
        }

        else {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size\n");
        return 0;
    }

    int arr[n];

    printf("Enter array elements (0, 1, 2 only): ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < 0 || arr[i] > 2) {
            printf("Invalid input! Only 0, 1, 2 allowed.\n");
            return 0;
        }
    }

    dutchNationalFlag(arr, n);

    printf("Sorted Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

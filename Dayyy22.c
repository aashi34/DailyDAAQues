/*Question No. 22

Write a C program to shift all zeros to the end of an array.

1. Write a normal code.
2. Identify and implement the best optimal approach.
3. Analyze both Time and Space Complexity.

The relative order of non-zero elements must remain unchanged.
*/

#include <stdio.h>

// Approach 1: Normal Method (Using Extra Array)
void normalMethod(int arr[], int n) {

    int temp[n];
    int j = 0;

    // Store non-zero elements
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }

    // Fill remaining positions with zero
    while (j < n) {
        temp[j++] = 0;
    }

    printf("1. Normal Method: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
}

// Approach 2: Optimal Two Pointer Method
void optimalMethod(int arr[], int n) {

    int j = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] != 0) {

            // Swap non-zero element with position j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            j++;
        }
    }

    printf("2. Optimal Method: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size");
        return 0;
    }

    int arr[n];
    int copy[n];

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        copy[i] = arr[i];
    }

    printf("\n--- Move Zeros to End ---\n");

    normalMethod(arr, n);
    optimalMethod(copy, n);

    return 0;
}

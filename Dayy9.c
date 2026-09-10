/*
Question 9: Rotate Array (LeetCode 189)

Given an integer array nums, rotate the array to the right by k steps.

Use the optimal three-step reversal method.

The solution must run in:
Time Complexity: O(N)
Space Complexity: O(1)

Example:
Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Output: [5, 6, 7, 1, 2, 3, 4]
*/

#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of rotations: ");
    scanf("%d", &k);

    k = k % n;

    // Step 1: Reverse the entire array
    reverse(arr, 0, n - 1);

    // Step 2: Reverse the first k elements
    reverse(arr, 0, k - 1);

    // Step 3: Reverse the remaining elements
    reverse(arr, k, n - 1);

    printf("Rotated array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

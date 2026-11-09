/* Question No. 25
Find Peak Element (LeetCode 162)

A peak element is an element that is strictly greater
than its neighbors.
Given a 0-indexed integer array nums, find a peak element and return its index.

If multiple peaks exist, return the index of any peak. Assume nums[-1] = nums[n] = negative infinity.
Adjacent elements are guaranteed to be different.
*/

#include <stdio.h>

int findPeakElement(int nums[], int n) {

    int low = 0;
    int high = n - 1;

    while (low < high) {

        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[mid + 1]) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }

    return low;
}

int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size");
        return 0;
    }

    int nums[n];

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int peak = findPeakElement(nums, n);

    printf("Peak Element Index = %d\n", peak);
    printf("Peak Element = %d\n", nums[peak]);

    return 0;
}

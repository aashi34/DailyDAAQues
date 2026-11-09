/*Question No. 24
Sort Array by Parity (LeetCode 905)
Given an integer array nums, move all the even integers at the beginning of the array followed by all odd integers.
Return the rearranged array.
*/

#include <stdio.h>

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

    int left = 0;
    int right = n - 1;

    while (left < right) {

        // If left element is even, move forward
        if (nums[left] % 2 == 0) {
            left++;
        }

        // If right element is odd, move backward
        else if (nums[right] % 2 != 0) {
            right--;
        }

        // Swap odd element with even element
        else {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }
    }

    printf("Array after rearranging: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

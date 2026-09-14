/* Q13: Trapping Rain Water
Given an array representing heights of bars,calculate how much rain water can be trapped.

Use Two Pointer technique.
Time Complexity: O(n)
Space Complexity: O(1)

Input:  3 0 2 0 4
Output: 7 */

#include <stdio.h>

int main() {

    int a[] = {3, 0, 2, 0, 4};
    int n = 5;

    int left = 0, right = n - 1;
    int lMax = 0, rMax = 0;
    int water = 0;

    while (left <= right) {

        if (a[left] <= a[right]) {

            if (a[left] >= lMax)
                lMax = a[left];
            else
                water += lMax - a[left];

            left++;
        }
        else {

            if (a[right] >= rMax)
                rMax = a[right];
            else
                water += rMax - a[right];

            right--;
        }
    }

    printf("Trapped Water = %d", water);

    return 0;
}

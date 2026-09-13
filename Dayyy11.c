/* Question 11:
In an array, square every element and return the elements in sorted order without sorting again.
Input:  -4 -3 -5 1 2 3
Output: 1 4 9 9 16 25 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int a[] = {-5, -4, -3, 1, 2, 3};
    int n = 6;
    int ans[6];

    int left = 0, right = n - 1;

    // Fill the answer array from right to left
    for (int i = n - 1; i >= 0; i--) {

        if (abs(a[left]) > abs(a[right])) {
            ans[i] = a[left] * a[left];
            left++;
        } else {
            ans[i] = a[right] * a[right];
            right--;
        }
    }

    // Print the sorted squared array
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}

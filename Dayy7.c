/*Question 7: 
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. 
Return the single element that appears only once. 
Your solution must run in O(log n) time and O(1) space. 
Input: nums = [1,1,2,3,3,4,4,8,8] 
Output: 2 */
#include <stdio.h>

int main() {
    int n, low, high, mid;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = low + (high - low) / 2;

        if (mid % 2 == 1) {
            mid--;
        }

        if (nums[mid] == nums[mid + 1]) {
            low = mid + 2;
        }
        else {
            high = mid;
        }
    }

    printf("Single element = %d\n", nums[low]);

    return 0;
}

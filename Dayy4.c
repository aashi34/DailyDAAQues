/* Day 4 Question: 
Given an integer array arr and a target value target, find the indices of two elements whose sum equals target.  Assume exactly one valid pair exists, and the same element cannot be used twice.
Input:
arr = [2, 7, 11, 15]
target = 9

Output:
[0, 1] */
#include <stdio.h>

int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = 4;
    int i = 0, j;

    while (i < n) {
        j = i + 1;

        while (j < n) {
            if (arr[i] + arr[j] == target) {
                printf("[%d, %d]", i, j);
                return 0;
            }
            j++;
        }

        i++;
    }

    return 0;
}

/* Question 15: Given two arrays arr1 and arr2, find the smallest difference between any two array elements. */
#include <stdio.h>
#include <stdlib.h>

int main() {

    int arr1[] = {1, 5, 10, 20, 3};
    int arr2[] = {2, 8, 15, 19};

    int n = 5, m = 4;
    int minDiff = 999999;

    // Compare every element of arr1 with every element of arr2
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int diff = abs(arr1[i] - arr2[j]);

            if (diff < minDiff)
                minDiff = diff;
        }
    }

    printf("Smallest Difference = %d", minDiff);

    return 0;
}

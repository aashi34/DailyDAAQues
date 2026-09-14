/* Q14: Given two sorted arrays nums1 and nums2,return the median of the two sorted arrays. */
#include <stdio.h>

int main() {

    int nums1[] = {1, 3};
    int nums2[] = {2};

    int m = 2, n = 1;
    int merged[3];

    int i = 0, j = 0, k = 0;

    // Merge both sorted arrays
    while (i < m && j < n) {
        if (nums1[i] < nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }

    while (i < m)
        merged[k++] = nums1[i++];

    while (j < n)
        merged[k++] = nums2[j++];

    int total = m + n;
    double median;

    // Find median
    if (total % 2 == 1)
        median = merged[total / 2];
    else
        median = (merged[total / 2 - 1] + merged[total / 2]) / 2.0;

    printf("Median = %.2f", median);

    return 0;
}

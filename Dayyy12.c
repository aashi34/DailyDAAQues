/* Q12: Remove duplicates from a sorted array.
Input:  5 5 7 8 8 9 9 10 10
Output: 5 7 8 9 10 */

#include <stdio.h>

int main() {

    int a[] = {5, 5, 7, 8, 8, 9, 9, 10, 10};
    int n = 9;

    int j = 0;

    // Compare each element with the previous unique element
    for (int i = 1; i < n; i++) {
        if (a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }

    // Print array without duplicates
    for (int i = 0; i <= j; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

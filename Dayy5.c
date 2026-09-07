/* Day 5: 
Input a number from the user and print 
a. Number of 1 and number of 0 in its binary representation. 
b. Number of consecutive 1 in the binary representation. */
#include <stdio.h>

int main() {
    int n;
    int ones = 0, zeros = 0;
    int consecutive = 0, maxConsecutive = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {

        if (n % 2 == 1) {
            ones++;
            consecutive++;

            if (consecutive > maxConsecutive) {
                maxConsecutive = consecutive;
            }
        }
        else {
            zeros++;
            consecutive = 0;
        }

        n = n / 2;
    }

    printf("Number of 1s = %d\n", ones);
    printf("Number of 0s = %d\n", zeros);
    printf("Maximum consecutive 1s = %d\n", maxConsecutive);

    return 0;
}

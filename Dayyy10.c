/*
Question 10:
Write a C program to print a hollow square pattern using '*'.

Example for n = 5:

* * * * *
*       *
*       *
*       *
* * * * *

The program should work for any value of n.
*/

#include <stdio.h>

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            if (i == 1 || i == n || j == 1 || j == n) {
                printf("* ");
            }
            else {
                printf("  ");
            }
        }

        printf("\n");
    }

    return 0;
}

/* Question 6: 
Write a generalised code for the following pattern (example is for n=4) 
A B C D
B C D E
C D E F
D E F G
You have to write a program that works for all value of n */

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", 'A' + i + j);
        }
        printf("\n");
    }

    return 0;
}

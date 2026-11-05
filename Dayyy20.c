/* Question No. 20
Write a C program to print the longest substring
without repeating a character.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int last[256];
    int start = 0, maxStart = 0;
    int maxLength = 0;

    printf("Enter string: ");
    scanf("%999s", s);

    // Initialize all positions to -1
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    // Sliding Window
    for (int i = 0; s[i] != '\0'; i++) {

        unsigned char ch = s[i];

        if (last[ch] >= start) {
            start = last[ch] + 1;
        }

        last[ch] = i;

        int length = i - start + 1;

        if (length > maxLength) {
            maxLength = length;
            maxStart = start;
        }
    }

    printf("Longest substring: ");

    for (int i = maxStart; i < maxStart + maxLength; i++) {
        printf("%c", s[i]);
    }

    printf("\nLength: %d\n", maxLength);

    return 0;
}

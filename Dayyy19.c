/*
Question 17:

Given a string s, find the length of the longest substring
without duplicate characters.

A substring is a continuous part of a string.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: "abc" is the longest substring without
repeating characters.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: "b" is the longest substring.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: "wke" is one of the longest substrings.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    int last[256];
    int start = 0;
    int maxLength = 0;

    printf("Enter string: ");
    scanf("%s", s);

    // Initialize all positions to -1
    for (int i = 0; i < 256; i++)
    {
        last[i] = -1;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        // If character already exists in current substring
        if (last[(unsigned char)s[i]] >= start)
        {
            start = last[(unsigned char)s[i]] + 1;
        }

        // Store latest position of character
        last[(unsigned char)s[i]] = i;

        // Calculate current substring length
        int currentLength = i - start + 1;

        // Update maximum length
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }

    printf("Length of longest substring = %d\n", maxLength);

    return 0;
}

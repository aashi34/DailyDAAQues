/* Day 3 Given an array of daily temperatures, find the length of the longest consecutive strictly increasing streak. 
Input: [10, 12, 15, 14, 16, 18, 20] 
Output: 4 
Explanation: 14, 16, 18, 20 is the longest increasing streak.*/
#include <stdio.h>

int main() {
    int temp[] = {10, 12, 15, 14, 16, 18, 20};
    int n = 7;

    int current = 1;
    int longest = 1;

    int i = 1;

    while (i < n) {
        if (temp[i] > temp[i - 1]) {
            current++;

            if (current > longest) {
                longest = current;
            }
        } 
        else {
            current = 1;
        }

        i++;
    }

    printf("Longest increasing streak: %d", longest);

    return 0;
}

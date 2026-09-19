/*Question 11: Secure Password Chef is planning to set up a secure password for his CodeChef account. For a password to be secure, the following conditions must be satisfied:

1. Password must contain at least one lowercase letter [a-z].
2. Password must contain at least one uppercase letter [A-Z]
   strictly inside the password.
   (The first and last characters will not be considered.)
3. Password must contain at least one digit [0-9]
   strictly inside the password.
4. Password must contain at least one special character
   from the set {'@', '#', '%', '&', '?'}
   strictly inside the password.
5. Password must be at least 10 characters long.
Write a C program to check whether the given password
is secure or not.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int lower = 0, upper = 0, digit = 0, special = 0;

    printf("Enter password: ");
    scanf("%s", s);

    int n = strlen(s);

    for (int i = 0; i < n; i++) {

        // Check lowercase letter (can be anywhere)
        if (s[i] >= 'a' && s[i] <= 'z') {
            lower = 1;
        }

        // Uppercase, digit and special character
        // must be strictly inside
        if (i > 0 && i < n - 1) {

            if (s[i] >= 'A' && s[i] <= 'Z') {
                upper = 1;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                digit = 1;
            }

            if (s[i] == '@' || s[i] == '#' ||
                s[i] == '%' || s[i] == '&' ||
                s[i] == '?') {
                special = 1;
            }
        }
    }

    // Check all conditions
    if (n >= 10 && lower && upper && digit && special) {
        printf("Secure Password");
    }
    else {
        printf("Not Secure Password");
    }

    return 0;
}

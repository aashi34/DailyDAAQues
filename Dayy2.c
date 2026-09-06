/*Day 2 Write a program using a while loop that repeatedly asks the user to enter the password and stops only when the correct password is entered. 
Finally, display "Login successful!*/
#include <stdio.h>
#include <string.h>

int main() {
    char password[20];

    printf("Enter password: ");
    scanf("%s", password);

    while (strcmp(password, "admin123") != 0) {
        printf("Incorrect password. Try again: ");
        scanf("%s", password);
    }

    printf("Login successful!");

    return 0;
}

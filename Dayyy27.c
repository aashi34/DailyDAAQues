/*Question No. 27
A mall has a 2D parking layout (rows and columns). Some spots are empty (0), and some are occupied (1).
Write a C program to automatically find the first available parking spot for an arriving car and park it.
Conditions:
1. 0 represents an empty parking spot.
2. 1 represents an occupied parking spot.
3. Find the first available spot in row-wise order.
4. Change 0 to 1 after parking the car.
5. If all spots are occupied, display "Parking Full".
*/

#include <stdio.h>

int main() {

    int rows, cols;
    int parked = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Invalid parking dimensions\n");
        return 0;
    }

    int parking[rows][cols];

    printf("Enter parking layout (0 = Empty, 1 = Occupied):\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &parking[i][j]);

            if (parking[i][j] != 0 && parking[i][j] != 1) {
                printf("Invalid parking value\n");
                return 0;
            }
        }
    }

    // Find the first empty parking spot
    for (int i = 0; i < rows && !parked; i++) {
        for (int j = 0; j < cols; j++) {

            if (parking[i][j] == 0) {

                parking[i][j] = 1;
                parked = 1;

                printf("\nCar parked at Row %d, Column %d\n",
                       i + 1, j + 1);

                break;
            }
        }
    }

    if (!parked) {
        printf("\nParking Full! No empty spot available.\n");
    }

    // Display updated parking layout
    printf("\nUpdated Parking Layout:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", parking[i][j]);
        }
        printf("\n");
    }

    return 0;
}

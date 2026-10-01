#include <stdio.h>
#include <time.h>

int main() {
    int arr[1000], n, key;
    int low, high, mid, i;
    clock_t start, end;
    double execution_time;

    printf("Enter number of elements (Maximum 1000): ");
    scanf("%d", &n);

    // Automatically fill the array with sorted elements
    for(i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    start = clock();

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            end = clock();
            execution_time = (double)(end - start) / CLOCKS_PER_SEC;

            printf("Element found at index %d\n", mid);
            printf("Execution Time = %.12f seconds\n", execution_time);
            return 0;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    end = clock();
    execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Element not found\n");
    printf("Execution Time = %.10f seconds\n", execution_time);

    return 0;
}
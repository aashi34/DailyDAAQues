/* Question No. 23
Write a C program to implement the Bucket Sort Algorithm.

Bucket Sort is a sorting algorithm that distributes elements into different buckets, sorts each bucket individually, and combines them to obtain the final sorted array.
*/

#include <stdio.h>
#include <stdlib.h>

// Insertion Sort for individual buckets
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Bucket Sort
void bucketSort(int arr[], int n) {

    if (n <= 1)
        return;

    int min = arr[0], max = arr[0];

    // Find minimum and maximum
    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    int k = n;

    // Create buckets
    int **buckets = malloc(k * sizeof(int *));
    int *count = calloc(k, sizeof(int));

    if (buckets == NULL || count == NULL) {
        printf("Memory allocation failed\n");
        free(buckets);
        free(count);
        return;
    }

    for (int i = 0; i < k; i++) {
        buckets[i] = malloc(n * sizeof(int));

        if (buckets[i] == NULL) {
            printf("Memory allocation failed\n");
            for (int j = 0; j < i; j++)
                free(buckets[j]);
            free(buckets);
            free(count);
            return;
        }
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(((long long)arr[i] - min)
                    * (k - 1) / ((long long)max - min + 1));

        buckets[index][count[index]++] = arr[i];
    }

    // Sort each bucket
    for (int i = 0; i < k; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // Combine all buckets
    int index = 0;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < k; i++)
        free(buckets[i]);

    free(buckets);
    free(count);
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size\n");
        return 0;
    }

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

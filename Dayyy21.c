/* Question No. 21
Find the Kth Largest Element in an Array.

Solve using three approaches:
1. With Sorting
2. Without Sorting
3. Optimal Approach (Quickselect)

Time and Space Complexity:

1. Sorting (Bubble Sort)
   Time: O(n^2)
   Space: O(1)

2. Without Sorting (Repeated Maximum)
   Time: O(n*k)
   Space: O(1)

3. Quickselect (Optimal Average Case)
   Average Time: O(n)
   Worst Time: O(n^2)
   Space: O(1)
*/

#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Approach 1: Using Sorting
int sortingMethod(int arr[], int n, int k) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    return arr[k - 1];
}

// Approach 2: Without Sorting
int withoutSorting(int arr[], int n, int k) {

    for (int i = 0; i < k; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }

        swap(&arr[i], &arr[maxIndex]);
    }

    return arr[k - 1];
}

// Partition function for Quickselect
int partition(int arr[], int low, int high) {

    int mid = low + (high - low) / 2;
    swap(&arr[mid], &arr[high]);

    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {

        if (arr[j] > pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

// Approach 3: Quickselect
int quickselect(int arr[], int n, int k) {

    int low = 0;
    int high = n - 1;
    int target = k - 1;

    while (low <= high) {

        int p = partition(arr, low, high);

        if (p == target) {
            return arr[p];
        }
        else if (p < target) {
            low = p + 1;
        }
        else {
            high = p - 1;
        }
    }

    return -1;
}

int main() {

    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size\n");
        return 0;
    }

    int arr[n], arr1[n], arr2[n], arr3[n];

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Copy array for all three methods
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid value of k\n");
        return 0;
    }

    printf("\n--- Kth Largest Element ---\n");

    printf("1. Using Sorting: %d\n",
           sortingMethod(arr1, n, k));

    printf("2. Without Sorting: %d\n",
           withoutSorting(arr2, n, k));

    printf("3. Using Quickselect: %d\n",
           quickselect(arr3, n, k));

    return 0;
}

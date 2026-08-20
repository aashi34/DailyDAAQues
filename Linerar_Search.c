// // Linear Search in C
// #include <stdio.h>
// #include <time.h>

// int main() {
//     int arr[100], n, key, i;
//     clock_t start, end;
//     double cpu_time_used;

//     start = clock();
//     printf("Enter number of elements in the array: ");
//     scanf("%d", &n);

//     printf("Enter %d elements:\n", n);
//     for (i = 0; i < n; i++) {                                                                   //stores the elements one by one in the array
//         scanf("%d", &arr[i]);
//     }
//     printf("Enter the element to search: ");
//     scanf("%d", &key);

//     for(i = 0; i < n; i++) {                                                                       
//         if (arr[i] == key) {
//             printf("Element found at index %d\n", i);
//             return 0;
//         }
//     }
//     printf("Element not found\n");
//     printf("CPU time used: %f seconds\n", cpu_time_used);
//     end = clock();
//     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
//     return 0;
// }

// #include <stdio.h>
// #include <time.h>

// int main() {
//     int arr[100], n, key, i, low, high, mid;
//     clock_t start, end;
//     double cpu_time_used;

//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     printf("Enter %d elements in sorted order:\n", n);
//     for(i = 0; i < n; i++)
//         scanf("%d", &arr[i]);

//     printf("Enter the element to search: ");
//     scanf("%d", &key);

//     low = 0;
//     high = n - 1;

//     start = clock();    // Start timing

//     while(low <= high) {
//         mid = (low + high) / 2;

//         if(arr[mid] == key) {
//             end = clock();   // End timing
//             cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

//             printf("Element found at index %d\n", mid);
//             printf("Execution Time = %.12f seconds\n", cpu_time_used);
//             return 0;
//         }
//         else if(arr[mid] < key)
//             low = mid + 1;
//         else
//             high = mid - 1;
//     }

//     end = clock();
//     cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

//     printf("Element not found\n");
//     printf("Execution Time = %.12f seconds\n", cpu_time_used);

//     return 0;
// }

#include <stdio.h>
#include <time.h>

int main() {
    int arr[1000], n, key, i;
    clock_t start, end;
    double execution_time;

    printf("Enter number of elements (Maximum 1000): ");
    scanf("%d", &n);

    // Automatically fill the array
    for(i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    start = clock();

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            end = clock();
            execution_time = (double)(end - start) / CLOCKS_PER_SEC;

            printf("Element found at index %d\n", i);
            printf("Execution Time = %.12f seconds\n", execution_time);
            return 0;
        }
    }

    end = clock();
    execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Element not found\n");
    printf("Execution Time = %.12f seconds\n", execution_time);

    return 0;
}
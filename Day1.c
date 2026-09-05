#include<stdio.h>

int main()
{
    int arr[100], even[100], odd[100];
    int n, e = 0, o = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        {
            even[e] = arr[i];
            e++;
        }
        else
        {
            odd[o] = arr[i];
            o++;
        }
    }

    printf("Even elements: ");
    for(int i = 0; i < e; i++)
    {
        printf("%d ", even[i]);
    }

    printf("\nOdd elements: ");
    for(int i = 0; i < o; i++)
    {
        printf("%d ", odd[i]);
    }

    return 0;
}
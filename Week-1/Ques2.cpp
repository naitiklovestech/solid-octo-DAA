#include <stdio.h>

int binarySearch(int arr[], int n, int key, int *comparisons)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        (*comparisons)++; 

        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1; 
        }
        else
        {
            high = mid - 1; 
        }
    }
    return -1; 
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int comparisons = 0;

    int index = binarySearch(arr, n, key, &comparisons);

    if (index != -1)
    {
        printf("Element %d found at index %d\n", key, index);
    }
    else
    {
        printf("Element %d not found in the array\n", key);
    }

    printf("Total comparisons: %d\n", comparisons);

    return 0;
}

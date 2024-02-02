#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int key)
{
    int step = sqrt(n); // Determine the block size to jump ahead
    int prev = 0;

    // Jump ahead in the array
    while (arr[(int)fmin(step, n) - 1] < key)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
        {
            return -1; // Key is not present in the array
        }
    }

    // Perform linear search in the found interval
    while (arr[prev] < key)
    {
        prev++;
        if (prev == fmin(step, n))
        {
            return -1; // Key is not present in the array
        }
    }

    // If element is found, return its index
    if (arr[prev] == key)
    {
        return prev;
    }

    return -1; // Key is not present in the array
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 11;

    int index = jumpSearch(arr, n, key);

    if (index != -1)
    {
        printf("Element %d found at index %d\n", key, index);
    }
    else
    {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n)
{
    int i, j, min_index, temp;
    for(i = 0; i < n - 1; i++)
    {
        min_index = i;
        // Find minimum element
        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // Swap
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void generateRandomNumbers(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if(n <= 5000)
    {
        printf("Please enter a value greater than 5000\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    generateRandomNumbers(arr, n);
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n",
           n, time_taken);
    free(arr);
    return 0;
}
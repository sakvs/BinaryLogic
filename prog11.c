#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to merge two sorted arrays
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[100000];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}
// Function to implement Merge Sort
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void generateRandomArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 5000)
    {
        printf("Please enter a value greater than 5000\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    generateRandomArray(arr, n);
    clock_t start = clock();
    for (int i = 0; i < 1000; i++)
    {
        mergeSort(arr, 0, n - 1);
    }
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);
    free(arr);
    return 0;
}
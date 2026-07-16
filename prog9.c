#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectionsort(int arr[], int n){
    int minindex;

    for(int i=0;i<=n-1;i++){
        minindex = i;
        for(int j = i+1; i<= n; j++){
            if(arr[j]<arr[minindex])
            minindex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }


    }
        
    void genrat(int arr[],int n){
        for(int i = 0; i< n; i++){
            arr[i] = rand() % 10000;
    }
}

int main(){
    int n;

    printf("enytr numbert of elements: ");
    scanf("%d",&n);

    if(n<=50000){
        printf("grater then 5000 \n");
        return 1;
    }
    int *arr = (int *)malloc(n*sizeof(int));

    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    genrat(arr , n);

    clock_t s = clock();

    selectionsort(arr, n);

    clock_t e = clock();

    double time_taken = ((double)(e-s))/ CLOCKS_PER_SEC;

    printf("time to sort %d elements: %f seconds\n",n,time_taken);

    free(arr);

    return 0;

}
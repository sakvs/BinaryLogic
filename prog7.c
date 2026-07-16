#include<stdio.h>
#define max 50

void greedyknapsack(int n, int w[], int p[], int mx)
{
    double x[max] = {0};      // solution vector
    double ratio[max];
    double profit = 0;

    // Calculate ratio = profit/weight
    for(int i = 0; i < n; i++)
        ratio[i] = (double)p[i] / w[i];

    // Sort based on ratio
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                int temp1 = w[i];
                w[i] = w[j];
                w[j] = temp1;

                int temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }

    // Select items
    for(int i = 0; i < n; i++)
    {
        if(mx > 0 && w[i] <= mx)
        {
            x[i] = 1;
            profit += p[i];
            mx -= w[i];
        }
        else
        {
            x[i] = (double)mx / w[i];
            profit += x[i] * p[i];
            break;
        }
    }

    printf("\nOptimal solution for greedy method: %.21f", profit);

    printf("\nSolution vector:\n");

    for(int i = 0; i < n; i++)
        printf("%.2lf\t", x[i]);
}

int main()
{
    int n, mx;
    int w[max], p[max];

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter profits:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    
    printf("Enter weights:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &w[i]);



    printf("Enter max capacity: ");
    scanf("%d", &mx);

    greedyknapsack(n, w, p, mx);

    return 0;
}
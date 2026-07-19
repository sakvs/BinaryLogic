#include <stdio.h>
#define MAX 50

void greedyKnapsack(int n, int w[], int p[], int capacity) {
    double ratio[MAX];
    double x[MAX]; // solution vector - use double for fractions
    double maxProfit = 0.0;
    int currentWeight = 0;

    // Initialize solution vector
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    // Calculate profit/weight ratio for each item
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)p[i] / w[i];
    }

    // Sort items by ratio in non-increasing order
    // Bubble sort - also swap w[] and p[] to keep them aligned
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                double tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;

                // Swap weights
                int tempW = w[i];
                w[i] = w[j];
                w[j] = tempW;

                // Swap profits
                int tempP = p[i];
                p[i] = p[j];
                p[j] = tempP;
            }
        }
    }

    // Fill the knapsack
    for (int i = 0; i < n; i++) {
        if (currentWeight + w[i] <= capacity) {
            // Take whole item
            x[i] = 1.0;
            currentWeight += w[i];
            maxProfit += p[i];
        } else {
            // Take fractional part of item
            int remaining = capacity - currentWeight;
            x[i] = (double)remaining / w[i];
            maxProfit += x[i] * p[i];
            break; // knapsack is full
        }
    }

    printf("Optimal solution for greedy method: %.2f\n", maxProfit);
    printf("Solution vector for greedy method: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
    }
    printf("\n");
}

int main() {
    int n, capacity;
    int w[MAX], p[MAX];

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the objects' weights: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the objects' profits: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the maximum capacity: ");
    scanf("%d", &capacity);

    greedyKnapsack(n, w, p, capacity);
    return 0;
}
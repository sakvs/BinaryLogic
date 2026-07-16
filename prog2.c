// Online C compiler to run C program online
#include <stdio.h>
#define INF 999

int prims(int c[10][10], int n, int s) {
    int v[10], par[10], dist[10];
    int i, j, sum = 0, min, u;

    for (i = 1; i <= n; i++) {
        par[i] = s;
        dist[i] = c[s][i];
        v[i] = 0;
    }
    v[s] = 1;

    for (i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1) break;

        v[u] = 1;
        sum += dist[u];
        printf("\n%d -> %d (cost: %d) total: %d", par[u], u, dist[u], sum);

        for (j = 1; j <= n; j++) {
            if (v[j] == 0 && c[u][j] < dist[j]) {
                dist[j] = c[u][j];
                par[j] = u;
            }
        }
    }
    return sum;
}


int main() {
    
    int c[10][10],n,s,result,i,j;
    
    printf("Enter a number of n value:");
    scanf("%d",&n);
    
    printf("Enter a graph data(adj matrix):");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&c[i][j]);
    
    printf("Enter a source node:");
    scanf("%d",&s);
    
    result = prims(c,n,s);
    
    printf("the result is %d:",result);
    return 0;
}
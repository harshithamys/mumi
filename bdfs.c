#include <stdio.h>

int a[10][10], s[10], n;

void bfs(int a[10][10], int n, int u) {
    int f, r, q[10], v;
    printf("BFS from node %d:", u);
    f = 0, r = -1;
    q[++r] = u;
    s[u] = 1;
    printf(" %d", u);
    while (f <= r) {
        u = q[f++];
        for (v = 0; v < n; v++) {
            if (a[u][v] == 1) {
                if (s[v] == 0) {
                    printf(" %d", v);
                    s[v] = 1;        
                    q[++r] = v;
                }
            }
        }
    }
    printf("\n");
}

void dfs(int u) {
    int v;
    s[u] = 1;
    printf("%d ", u);
    for (v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0)
            dfs(v);
    }
}

int main() {
    int source, i, j;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (source = 0; source < n; source++) {
        bfs(a, n, source);
    }

    for (source = 0; source < n; source++) {
        for (i = 0; i < n; i++)
            s[i] = 0;
        printf("DFS from node %d: ", source);
        dfs(source);
        printf("\n");
    }

    return 0;
}
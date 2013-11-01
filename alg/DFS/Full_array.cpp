/* 全排列 */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 10

int array[MAXN];
int n;

void dfs(int i);

int main() {
    while (scanf("%d", &n) != EOF) 
        dfs(0);
}

void dfs(int i) {
    int j, k;
    if (i == n) {
        for (int i = 0; i < n; ++i) 
            printf("%d ", array[i]);
        printf("\n");
        return;
    }
    for (k = 1; k <= n; ++k) {
        int ok = 1;
        for (j = 0; j < i; ++j) 
            if (array[j] == k)
                ok = 0;
        if (ok) {
            array[i] = k;
            dfs(i + 1);
        }
    }
}

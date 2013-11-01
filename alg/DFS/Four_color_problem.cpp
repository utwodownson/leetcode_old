/* 给定N（小于等于8）个点的地图，
 * 以及地图上各点的相邻关系，
 * 请输出用4种颜色将地图涂色的所有方案数（要求相邻两点不能涂成相同的颜色）
 * 数据中0代表不相邻，1代表相邻
 * input
 * 第一行一个整数n，代表地图上有n个点
 * 接下来n行，每行n个整数，每个整数是0或者1。第i行第j列的值代表了第i个点和第j个点之间是相邻的还是不相邻，相邻就是1，不相邻就是0.
 * 我们保证a[i][j] = a[j][i] （a[i,j] = a[j,i]）
 8
 0 0 0 1 0 0 1 0 
 0 0 0 0 0 1 0 1 
 0 0 0 0 0 0 1 0 
 1 0 0 0 0 0 0 0 
 0 0 0 0 0 0 0 0 
 0 1 0 0 0 0 0 0 
 1 0 1 0 0 0 0 0 
 0 1 0 0 0 0 0 0
 15552
 */

#include <stdio.h> 
#include <stdlib.h>

#define MAXN 8

int N;
int g[MAXN][MAXN];
int color[MAXN];
int count;

void dfs(int i) {
    int j, c;
    if (i == N) {
        count++;
        return;
    }

    for (c = 1; c < 5; ++c) {
        int ok = 1;
        for (j = 0; j < i; ++j) {
            if (g[i][j] && c == color[j])
                ok = 0;
        }
        if (ok) {
            color[i] = c;
            dfs(i + 1);
        }
    }
}

int main() {
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) 
                scanf("%d", &g[i][j]);
        dfs(0);
        printf("%d\n", count);
    }
    system("pause");
}

/* 八皇后 */
#include <stdio.h>
#include <stdlib.h>

#define N 8

int count = 0;
int a[N];
int left[2 * N]; // principal_diagonals
int right[2 * N]; // counter_dagonals

void print() {
    printf("No. %d\n", count);
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            if (a[i] != j) printf("0 ");
            else printf("1 ");
        }
        printf("\n");
    }
}

int check(const int row, const int column) {
    int ok = 1;
    for (int i = 0; i < row; ++i) {
        if (column == a[i] || row - i == abs(column - a[i])) {
            ok = 0;
            break;
        }
    }
    return ok;
}

int dfs(const int row) {
    if (row == N) {
        ++count;
        print();
        return count;
    }

    for (int j = 0; j < N; ++j) {
        const int ok = check(row, j);
        if (ok) {
            a[row] = j;
            dfs(row + 1);
        }
    }
    return count;
}

int main() {
    printf("%d\n", dfs(0));
}

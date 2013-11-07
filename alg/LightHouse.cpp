#include <stdio.h>
#include <stdlib.h>

#define N 500010

typedef struct _Node {
    int x;
    int y;
}Node;

Node a[N];
int y[N];
int buf[N];
int n;
long long num;

void mergesort(int left, int right) {
    if (left >= right) 
        return;
    int mid = left + ((right - left) >> 1);
    mergesort(left, mid);
    mergesort(mid + 1, right);

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (y[i] < y[j]) {
            buf[k++] = y[j++];
            num += mid - i + 1; 
        } else {
            buf[k++] = y[i++];
        }
    }
    while (i <= mid) 
        buf[k++] = y[i++];
    while (j <= right)
        buf[k++] = y[j++];
    for (int p = 0; p < k; ++p)
        y[p + left] = buf[p];
}

int cmp(const void *a, const void *b) {
    return (*(Node *)a).x >= (*(Node *)b).x ? 1 : -1;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        num = 0;
        for (int i = 0; i < n; ++i) 
            scanf("%d%d", &a[i].x, &a[i].y);

        qsort(a, n, sizeof(Node), cmp);

        //printf("\n");
        for (int i = 0; i < n; ++i) {
            //printf("%d %d\n", a[i].x, a[i].y);
            y[i] = a[i].y;
        }

        mergesort(0, n - 1);

        printf("%lld\n", num);
    }
}

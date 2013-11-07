#include <stdio.h>
#include <stdlib.h>

#define N 12

void show(int *a) {
    for (int i = 0; i < N; ++i) 
        printf("%d ", a[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void insertion(int *a) {
    int j = 0;
    for (int i = 1; i < N; ++i) {
        int tmp = a[i];
        for (j = i - 1; tmp < a[j] && j >= 0; --j) // < 
            a[j + 1] = a[j];
        a[j + 1] = tmp; 
    }
}

void binary_insert(int *a) {
    for (int i = 1; i < N; ++i) {
        int tmp = a[i];

        // binary search
        int left = 0;
        int right = i - 1;
        while (left <= right) { // <=
            int mid = left + ((right - left) >> 1);
            if (tmp < a[mid]) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; --j)
            a[j + 1] = a[j];
        a[left] = tmp; // left
    }
}

void shell_insert(int *a) {
    int gap = N - 1, j = 0;
    while (gap > 1) { // >
        gap = gap / 3 + 1; 
        for (int i = gap; i < N; ++i) { // ++i
            int tmp = a[i];
            for (j = i - gap; tmp < a[j] && j >= 0; j -= gap)
                a[j + gap] = a[j];
            a[j + gap] = tmp;
        }
    }
}

void bubble(int *a) {
    int exchange;
    for (int i = 0; i < N; ++i) {
        exchange = 0; // 没有交换就退出
        for (int j = N - 1; j > i; --j) {
            if (a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
                exchange = 1;
            }
        }
        if (exchange == 0) return;
    }
}

void quick(int *a, int start, int end) {
    if (start < end - 1) { // 至少两个元素
        int mid = 0;
        int i = start;
        int j = end - 1;
        int tmp = a[i];
        while (i < j) {
            while (i < j && a[j] >= tmp) --j;
            if (i < j) a[i] = a[j];
            while (i < j && a[i] <= tmp) ++i;
            if (i < j) a[j] = a[i];
        }
        a[i] = tmp;
        mid = i;
        quick(a, start, mid);
        quick(a, mid + 1, end);
    }
}

void selection(int *a) {
    for (int i = 0; i < N; ++i) {
        int k = i;
        for (int j = i + 1; j < N; ++j) 
            if (a[j] < a[k]) 
                k = j;
        if (k != i) 
            swap(&a[i], &a[k]);
    }
}

void heap(int *a) {

}

void mergesort(int *a, int start, int end) {
    if (start < end) {
        int mid = start + ((end - start) >> 1);
        mergesort(a, start, mid);
        mergesort(a, mid + 1, end);

        int *tmp = (int *) malloc(sizeof(int) * N);
        if (!tmp) return;

        int i = start, j = mid + 1, k = 0; 
        while (i <= mid && j <= end) 
            tmp[k++] = a[i] < a[j] ? a[i++] : a[j++];

        while (i <= mid) tmp[k++] = a[i++];
        while (j <= end) tmp[k++] = a[j++];

        for (int p = 0; p < k; ++p) 
            a[start + p] = tmp[p];
        if (tmp) 
            free(tmp);

    }
}

void merge_sort_unrecursion(int *a) {
    int *buff = (int *) malloc(sizeof(int) * N);
    if (!buff) return;

    int left_min, left_max, right_min, right_max, next;

    for (int i = 1; i < N; i *= 2) {
        for (left_min = 0; left_min < N - i; left_min = right_max) {
            left_max = right_min = left_min + i;
            right_max = right_min + i;
            if (right_max > N)
                right_max = N;

            next = 0;
            while (left_min < left_max && right_min < right_max)
                buff[next++] = a[left_min] <= a[right_min] ? a[left_min++] : a[right_min++];
            while (left_min < left_max)
                a[--right_min] = a[--left_max];
            while (next > 0)
                a[--right_min] = buff[--next];
        }
    }
    if (buff) free(buff);
}

int main() 
{
    int a[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int b[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int c[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int d[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int e[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int f[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int g[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int h[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    int i[] = { 9, 2, 4, 6, 0, 1, 1, 0, 3, 8, 5, 7 };
    show(a);
    printf("\n");

    insertion(a); show(a);
    binary_insert(b); show(b);
    shell_insert(c); show(c);
    bubble(d); show(d);
    quick(e, 0, N); show(e);
    selection(f); show(f);
    mergesort(h, 0, N); show(h);
    merge_sort_unrecursion(i); show(i);
}

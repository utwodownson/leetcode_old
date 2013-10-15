#include <iostream>
#include <cstdio>
using namespace std;

int maxSubArray(int A[], int n) {
    // Note: The Solution object is instantiated only once and is reused by each test case.
    int sum = 0;
    int max = -888;
    int left, right;
    for (int i = 0; i < n; ++i) {
        sum += A[i];
        if (sum > max) 
            max = sum;
        if (sum < 0) 
            sum = 0;
    }
    return max;
}
int main() 
{
    int list[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; 
    int ans = maxSubArray(list, 9);
    printf("%d\n", ans);
}

/**
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0, j = n - 1;
            while (i <= j) {
                printf("i = %d\n", i);
                int mid = (i + j) / 2;
                if (A[mid] < target)
                    i = mid + 1;
                else
                    j = mid - 1;
            }
            return i;
        }
};

/* 
 * 1st 
 * Run Status: Time Limit Exceeded
 * Last executed input
 * [1,3], 2
 * result : wrong mid = i + (j - i) >> 1; the right is : int mid = i + ((j - i) >> 1); 
 */
int main(void) {
    Solution s;
    int A[100];
    int n, target;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%d", &A[i]);
    scanf("%d", &target);
    printf("test\n");
    cout << s.searchInsert(A, n, target) << endl;
}

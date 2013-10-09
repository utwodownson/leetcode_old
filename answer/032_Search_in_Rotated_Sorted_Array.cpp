/**
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * 
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * 
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 */

class Solution {
    public:
        int search(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int min = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] < A[min]) 
                    min = i;
            }

            int i = min, j = n - 1;
            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (target < A[mid]) 
                    j = mid - 1;
                else if (target > A[mid])
                    i = mid + 1;
                else 
                    return mid; 
            }

            if (min == 0) return -1;

            i = 0, j = min - 1;
            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (target < A[mid]) 
                    j = mid - 1;
                else if (target > A[mid])
                    i = mid + 1;
                else 
                    return mid; 
            }
            return -1;
        }
};
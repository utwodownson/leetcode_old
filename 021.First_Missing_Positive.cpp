/**
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 */

class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            for (int i = 0; i < n; ++i) {
                int id = i, tmp = A[id];
                while (id + 1 != tmp && id <= n && id > 0) {
                    id = tmp - 1;
                    tmp = A[id];
                    A[id] = id + 1;
                }
            }
            for (int i = 1; i < n; ++i) 
                if (A[i - 1] != i) 
                    return i; 
            return n + 1;
        }
};

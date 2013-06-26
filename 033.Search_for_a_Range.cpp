/**
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */

class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> ret(2, 0);
            int i = 0, j = n - 1;
            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (A[mid] < target) 
                    i = mid + 1;
                else
                    j = mid - 1;
            }
            if (A[i] != target) {
                ret[0] = -1;
                ret[1] = -1;
            } else {
                ret[0] = i;
                int j = i;
                while (j < n && A[j] == A[i]) j++;
                ret[1] = j - 1;
            }
            return ret;
        }
};

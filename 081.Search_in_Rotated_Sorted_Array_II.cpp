/**
 * Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * 
 * Would this affect the run-time complexity? How and why?
 * 
 * Write a function to determine if a given target is in the array.
 */


class Solution {
    public:
        bool search(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int min = 0;
            for (int j = 1; j < n; ++j) {
                if (A[j - 1] > A[j])
                    min = j;
            }

            int i = min, j = n - 1;
            if (A[i] == target) return true;
            if (j >= 0 && A[j] == target) return true; // point

            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (target < A[mid])
                    j = mid - 1;
                else if (target > A[mid])
                    i = mid + 1;
                else
                    return true;
            }

            if (min == 0) return false;

            i = 0, j = min - 1;
            if (A[i] == target) return true;
            if (j >= 0 && A[j] == target) return true;

            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (target < A[mid])
                    j = mid - 1;
                else if (target > A[mid])
                    i = mid + 1;
                else
                    return true;
            }
            return false;
        }
};




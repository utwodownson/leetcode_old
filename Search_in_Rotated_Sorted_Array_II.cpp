/* Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 */
class Solution {
        bool binary_search(int *a, int left, int right, int target) {
            int i = left, j = right;
            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (a[mid] == target)
                    return true;
                else if (a[mid] > target)
                    j = mid - 1;
                else 
                    i = mid + 1;
            }
            return false;
        }
    public:
        bool search(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int max = -1;
            for (int i = 0; i < n - 1; ++i) {
                if (max == -1 || A[i] >= A[max] && A[i + 1] < A[i]) 
                    max = i;
            }
            if (binary_search(A, 0, max, target)) return true;
            if (binary_search(A, max + 1, n - 1, target)) return true;
            return false;
        }
};

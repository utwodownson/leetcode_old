/* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */
class Solution {
    public:
        int binary_search(int *a, int left, int right, int target) {
            int i = left, j = right;
            if (i < 0 || j < 0) return -1;
            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (target < a[mid])
                    j = mid - 1;
                else if (target > a[mid]) 
                    i = mid  + 1;
                else
                    return mid;
            }
            return -1;
        }
        int search(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (n == 0) return -1;

            int min = 0, ans_left = -1, ans_right = -1;
            for (int i = 1; i < n; ++i) {
                if (A[i - 1] > A[i])
                    min = i; 
            }
            ans_left = binary_search(A, 0, min - 1, target);
            ans_right = binary_search(A, min, n - 1, target);
            return ans_left > ans_right ? ans_left : ans_right; 
        }
};

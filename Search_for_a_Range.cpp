/* Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
class Solution {
        int binary_search(int *A, int n, int target) {
            int low = 0, high = n, mid = 0;
            while (low < high) 
                (target < A[mid = (low + high) >> 1]) ? high = mid : low = mid + 1;
            return low - 1;
        }
    public:
        vector<int> searchRange(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> ans(2, -1);

            int left = binary_search(A, n, target - 1) + 1;
            if (A[left] != target) return ans;

            int right = binary_search(A, n, target);
            ans[0] = left;
            ans[1] = right;

            return ans;
        }
};

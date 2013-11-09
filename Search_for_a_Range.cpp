/* Given a sorted array of integers, find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> ans(2, 0);
            int i = 0, j = n - 1;
            while (i <= j) {
                int mid = i + ((j - i) >> 1);
                if (A[mid] < target) 
                    i = mid + 1;
                else 
                    j = mid - 1;
            }
            if (A[i] != target) {
                ans[0] = -1;
                ans[1] = -1;
            } else {
                ans[0] = i;
                j = i;
                while (j < n && A[j] == target) ++j;
                ans[1] = j - 1;
            }
            return ans;
        }
};

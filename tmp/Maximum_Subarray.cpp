/* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
class Solution {
    public:
        int maxSubArray(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> d(n, 0);

            d[0] = A[0];
            int ans = A[0];

            for (int i = 1; i < n; ++i) {
                d[i] = max(A[i], d[i - 1] + A[i]);
                if (ans < d[i])
                    ans = d[i];
            }
            return ans;
        }
};

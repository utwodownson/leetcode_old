/* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 * the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */
class Solution {
    public:
        int maxSubArray(int A[], int n, int* left, int* right, int *sum) {
            if (n == 1) {
                *left = *right = *sum = A[0];
                return A[0];
            } else {
                int m = n / 2;
                int lmax, rmax, ll, lr, rl, rr, lsum, rsum;
                lmax = maxSubArray(A, m, &ll, &lr, &lsum);
                rmax = maxSubArray(A+m, n-m, &rl, &rr, &rsum);
                *left = max(ll, lsum + rl);
                *right = max(rr, rsum + lr);
                *sum = lsum + rsum;
                return max(max(lmax, rmax), lr + rl);
            }
        }

        int maxSubArray(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int left, right, sum;
            return maxSubArray(A, n, &left, &right, &sum);
        }
};

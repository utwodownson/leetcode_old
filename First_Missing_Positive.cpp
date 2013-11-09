/* Given an unsorted integer array, find the first missing positive integer.
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * Your algorithm should run in O(n) time and uses constant space.
 */
class Solution {
    public:
        int firstMissingPositive(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            for (int i = 0; i < n; ++i) {
                int index = i, num = A[index];
                while (num != index + 1 && num <= n && num > 0) {
                    index = num - 1;
                    num = A[index];
                    A[index] = index + 1;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (A[i] != i + 1)
                    return i + 1;
            }
            return n + 1;
        }
};

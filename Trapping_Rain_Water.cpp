/* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
class Solution {
    public:
        int trap(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int i = 0, h = 0, ans = 0;
            for (int j = 0; j < n; ++j) 
                if (A[i] < A[j])
                    i = j;
            for (int j = 0; j < i; ++j) 
                (j != 0 && A[j] < h) ? ans += h - A[j] : h = A[j];
            for (int j = n - 1; j > i; --j) 
                (j != n - 1 && A[j] < h) ? ans += h - A[j] : h = A[j];
            return ans;
        }
};


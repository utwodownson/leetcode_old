/* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
class Solution {
    public:
        int trap(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int index = 0, ans = 0, h = 0;
            for (int i = 0; i < n; ++i) 
                if (A[i] > A[index])
                    index = i;
            for (int i = 0; i < index; ++i) 
                (i > 0 && h > A[i]) ? ans += h - A[i] : h = A[i];
            for (int i = n - 1; i > index; --i) 
                (i < n - 1 && A[i] < h) ? ans += h - A[i] : h = A[i];
            return ans;
        }
};


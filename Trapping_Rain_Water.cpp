/* Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 */
class Solution {
    public:
        int trap(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int maxp = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i] > A[maxp]) 
                    maxp = i;
            }

            int water = 0, h;
            for (int i = 0; i < maxp; ++i) {
                if (i > 0 && A[i] < h)
                    water += h - A[i];
                else
                    h = A[i];
            }

            for (int i = n - 1; i > maxp; --i) {
                if (i < n - 1 && A[i] < h)
                    water += h - A[i];
                else
                    h = A[i];
            }
            return water;
        }
};


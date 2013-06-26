/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */

class Solution {
    public:
        int trap(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int maxp = 0;
            for (int i = 0; i < n; ++i) {
                if (A[maxp] < A[i]) 
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

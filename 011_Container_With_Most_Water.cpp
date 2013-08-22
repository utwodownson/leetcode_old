/*
 * Given n non-negative integers a1, a2, ..., an, 
 * where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, 
 * such that the container contains the most water.
 * 
 * Note: You may not slant the container.
 */
class Solution {
    public:
        int maxArea(vector<int> &height) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int res = 0;
            int len = height.size();
            int mid = 0, max = 0;
            for (int i = 0; i < len; ++i) {
                if (max < a[i]) {
                    max = a[i];
                    mid = i;
                }
            }
            int left = 0, right = len - 1;
            while (left < mid) 
                if (a[left] > a[left + 1])
                    res += a[left++] - a[left + 1];
            while (right > mid)
                if (a[right] > a[right - 1]) 
                    res += a[right] - a[right + 1]; 
            return res;
        }
};

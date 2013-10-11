/* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 */

class Solution {
    public:
        int maxArea(vector<int> &height) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int max, area = 0, j = height.size() - 1, i = 0;
            while (i < j) {
                while (i < j && height[i] <= height[j]) {
                    area = (j - i) * height[i];
                    if (area > max) 
                        max = area;
                    i++;
                }
                while (i < j && height[i] > height[j]) {
                    area = (j - i) * height[j];
                    if (area > max)
                        max = area;
                    j--;
                }
            }
            return max;
        }
};

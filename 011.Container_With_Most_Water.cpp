class Solution {
    public:
        int maxArea(vector<int> &height) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0, j = height.size() - 1;
            int area = 0, maxarea = 0;
            while (i < j) {
                if (height[i] < height[j]) {
                    area = height[i] * (j - i);
                    ++i;
                } else {
                    area = height[j] * (j - i);
                    --j;
                }
                if (maxarea < area) maxarea = area;
            }
            return maxarea;
        }
};

/* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1
 * find the area of largest rectangle in the histogram.
 * Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
 * The largest rectangle is shown in the shaded area, which has area = 10 unit.
 * For example,
 * Given height = [2,1,5,6,2,3],
 * return 10.
 */
class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            stack<int> s;
            height.push_back(0);
            int ans = 0;
            for (int i = 0; i < height.size(); ++i) {
                if (s.empty() || height[i] > height[s.top()])
                    s.push(i);
                else {
                    int tmp = s.top();
                    s.pop();
                    ans = max(ans, height[tmp] * (s.empty() ? i : i - s.top() - 1));
                    --i;
                }
            }
            return ans;
        }
};

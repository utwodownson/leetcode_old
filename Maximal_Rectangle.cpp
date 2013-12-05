/* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. */
class Solution {
    int largest(vector<int> &height) {
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
    public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row <= 0) return 0;

        int col = matrix[0].size();

        vector<int> now(col, 0);
        int ans = 0;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) 
                now[j] = (matrix[i][j] == '1') ? ++now[j] : 0;
            ans = max(ans, largest(now));
        }
        return ans;
    }
};

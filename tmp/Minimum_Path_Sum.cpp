/* Given a m x n grid filled with non-negative numbers, 
 * find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */ 
class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int row = grid.size();
            int col = grid[0].size();
            vector<int> steps(col, INT_MAX);

            if (!row) return 0;
            if (!col) return 0;

            steps[0] = 0;
            for (int i = 0; i < row; ++i) {
                steps[0] = steps[0] + grid[i][0];
                for (int j = 1; j < col; ++j) 
                    steps[j] = min(steps[j], steps[j - 1]) + grid[i][j];
            }
            return steps[col - 1];
        }
};

/* Follow up for "Unique Paths":
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * [
    [0,0,0],
    [0,1,0],
    [0,0,0]
   ]
 * The total number of unique paths is 2.
 * Note: m and n will be at most 100.
 */
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<int> a(n, 0);

            if (!m) return 0;
            if (obstacleGrid[0][0] == 1) return 0;
            
            a[0] = 1;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (obstacleGrid[i][j] == 1)
                        a[j] = 0;
                    else if (j > 0) 
                        a[j] = a[j - 1] + a[j];
                }
            }
            return a[n - 1];
        }
};

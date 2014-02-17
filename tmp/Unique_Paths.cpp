/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 */
const int MAXN = 100 + 10;
int dp[MAXN][MAXN];

class Solution {
    int dfs(int i, int j) {
        if (dp[i][j] > 0) return dp[i][j];
        else return dp[i][j] = dfs(i - 1, j) + dfs(i, j - 1);
    }
    public:
    int uniquePaths(int m, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ans = 0;
        memset(dp, 0xff, sizeof(dp));
        for (int i = 1; i < MAXN; ++i) 
            dp[1][i] = dp[i][1] = 1;

        ans = dfs(m, n);

        return ans;
    }
};


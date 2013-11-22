/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 */
class Solution {
    public:
        int uniquePaths(int m, int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> a(n, 0);
            a[0] = 1;
            for (int i = 0; i < m; ++i) 
                for (int j = 1; j < n; ++j) 
                    a[j] = a[j - 1] + a[j];
            return a[n - 1];
        }
};

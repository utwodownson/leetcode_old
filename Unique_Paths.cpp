/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. 
 * The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 */
class Solution {
    public:
        int uniquePaths(int m, int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            double x = 1;
            if (m < n) swap(m, n);
            for (int i = 1; i < n; i++) 
                x = x * (m + i - 1) / i;
            return (x - (int)x >= 0.5 ? (int)x + 1: (int)x);
        }
};

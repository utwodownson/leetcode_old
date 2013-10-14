/* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * For example,
 * Given the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> ans;
            int rows = matrix.size();
            if (rows == 0) 
                return ans;
            int cols = matrix[0].size();
            
            int s, lap = min(rows, cols);
            for (s = 0; s < lap / 2; ++s) {
                int r = s, c = s;
                while (c < cols - s - 1) 
                    ans.push_back(matrix[r][c++]);
                while (r < rows - s - 1)
                    ans.push_back(matrix[r++][c]);
                while (c > s) 
                    ans.push_back(matrix[r][c--]);
                while (r > s)
                    ans.push_back(matrix[r--][c]);
            }
            if (lap & 1) {
                int r = s;
                while (r < rows - s) {
                    int c = s;
                    while (c < cols - s) {
                        ans.push_back(matrix[r][c]);
                        c++;
                    }
                    r++;
                }
            }
            return ans;
        }
};

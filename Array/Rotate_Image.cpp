/* You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */
class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            int n = matrix.size();
            for (int i = 0; i < n; ++i) 
                for (int j = 0; j < n - i; ++j) 
                    swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            for (int i = 0; i < n / 2; ++i) 
                swap(matrix[i], matrix[n - 1 - i]);
        }
};


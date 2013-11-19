/* You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 * Follow up:
 * Could you do this in-place?
 */
class Solution {
    void change(int &a, int &b, int &c, int &d) {
        int tmp = d;
        d = c;
        c = b;
        b = a;
        a = tmp;
    }
    public:
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) 
            for (int j = i; j + i + 1 < n; ++j) 
                change(matrix[i][j], 
                        matrix[j][n - 1 - i], 
                        matrix[n - 1 - i][n - 1 - j],
                        matrix[n - 1 - j][i]);
    }
};


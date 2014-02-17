/* Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */
class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int n = matrix.size();
            int m = matrix[0].size();
            int low = 0, high = n * m, mid = 0;
            while (low < high) {
                mid = (low + high) >> 1;
                int tmp = matrix[mid / m][mid % m];
                if (tmp == target) return true;
                else if (target < tmp) high = mid;
                else low = mid + 1;
            }
            return false;
        }
};

/* Write a program to solve a Sudoku puzzle by filling the empty cells.
 * Empty cells are indicated by the character '.'.
 * You may assume that there will be only one unique solution.
 * A sudoku puzzle...
 * ...and its solution numbers marked in red.
 */
class Solution {
    bool getBit(int x, int b) const {
        return (x >> b) & 1;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        vector<int> rows(9,0);
        vector<int> cols(9,0);
        vector<int> blocks(9,0);
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int blk = (r / 3) * 3 + c / 3;
                int n = board[r][c] - '1';
                if (getBit(rows[r], n) || getBit(cols[c], n) || getBit(blocks[blk], n)) {
                    return false;
                }
                rows[r] |= 1 << n;
                cols[c] |= 1 << n;
                blocks[blk] |= 1 << n;
            }
        }

        return true;
    }
    vector<bool> Valid(vector<vector<char> > &board, int x, int y) {
        vector<bool> sub(9, true);
        for (int i = 0; i < 9; ++i) {
            if (board[x][i] != '.') sub[board[x][i] - '1'] = false;
            if (board[i][y] != '.') sub[board[i][y] - '1'] = false;
        }

        int rx = (x / 3) * 3, ry = (y / 3) * 3;
        for (int i = rx; i < rx + 3; ++i)
            for (int j = ry; j < ry + 3; ++j)
                if (board[i][j] != '.')
                    sub[board[i][j] - '1'] = false;
        return sub;
    }

    bool solvehelper(vector<vector<char> > &board, int start) {
        for ( ; start < 81; ++start) {
            int x = start / 9, y = start % 9;
            if (board[x][y] == '.') {
                vector<bool> sub = Valid(board, x, y);
                for (int i = 0; i < 9; ++i) {
                    if (sub[i]) {
                        board[x][y] = i + '1';
                        if (solvehelper(board, start + 1))
                            return true;
                    }
                }
                if (board[x][y] == '.') return false;
                else board[x][y] = '.';
                break;
            }
        }
        if (start >= 80)
            if (isValidSudoku(board))
                return true;
        return false;
    }
    public:
    void solveSudoku(vector<vector<char> > &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        solvehelper(board, 0);
    }
};


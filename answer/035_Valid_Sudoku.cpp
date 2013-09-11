/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 * A partially filled sudoku which is valid.
 */

class Solution {
    public:
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
};

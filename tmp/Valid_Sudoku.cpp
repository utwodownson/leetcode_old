/**
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * A partially filled sudoku which is valid.
 */

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            vector<int> rows(9, 0), cols(9, 0), blocks(9, 0);

            for (int r = 0; r < 9; r++) {
                for (int c = 0; c < 9; c++) {
                    if (board[r][c] == '.') continue;

                    int blk = (r / 3) * 3 + c / 3;                
                    int n = board[r][c] - '1';                

                    if ((rows[r] >> n) & 1 || (cols[c] >> n) & 1 || (blocks[blk] >> n) & 1) 
                        return false;

                    rows[r] |= 1 << n;
                    cols[c] |= 1 << n;
                    blocks[blk] |= 1 << n;
                }
            }
            return true;
        }
};


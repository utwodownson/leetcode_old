/* Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 * A region is captured by flipping all 'O's into 'X's in that surrounded region .
 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 */
class Solution {
    public:
        void solve(vector<vector<char>> &board) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> xIndex, yIndex;
            int row = board.size();  
            if (row == 0) return;  
            int col = board[0].size();  
            xIndex.clear();  
            yIndex.clear();            
            for (int i = 0; i < row; ++i) {  
                if (board[i][0] == 'O') {  
                    xIndex.push_back(i);  
                    yIndex.push_back(0);  
                }  
                if (board[i][col - 1] == 'O') {  
                    xIndex.push_back(i);  
                    yIndex.push_back(col - 1);  
                }  
            }  
            for (int i = 0; i < col; i++) {  
                if (board[0][i] == 'O') {  
                    xIndex.push_back(0);  
                    yIndex.push_back(i);  
                }  
                if (board[row-1][i] == 'O') {  
                    xIndex.push_back(row - 1);  
                    yIndex.push_back(i);  
                }  
            }            

            int k = 0;  
            while (k < xIndex.size()) {  
                int x = xIndex[k];  
                int y = yIndex[k];     
                board[x][y] = 'Y';  
                if (x > 0 && board[x - 1][y] == 'O' ) {xIndex.push_back(x - 1); yIndex.push_back(y);}  
                if (x < row - 1 && board[x + 1][y] == 'O' ) {xIndex.push_back(x + 1); yIndex.push_back(y);}                 
                if (y  >0 && board[x][y - 1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y - 1);}  
                if (y < col - 1 && board[x][y + 1] == 'O' ) {xIndex.push_back(x); yIndex.push_back(y + 1);}  
                k++;  
            }  
            for (int i = 0; i < row; i++) {  
                for (int j = 0; j < col; j++)  {  
                    if (board[i][j] =='O') board[i][j] = 'X';  
                    if (board[i][j] == 'Y') board[i][j] = 'O';  
                }  
            }            
        }
};

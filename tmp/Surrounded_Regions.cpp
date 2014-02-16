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
        void visit(vector<vector<char> > &board, int i, int j, queue<int> &q) {
            const int m = board.size();
            const int n = board[0].size();
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'o') return;
            board[i][j] = '+';
            q.push(i * n + j);
        }
        void bfs(vector<vector<char> > &board, int i, int j) {
            queue<int> q;
            visit(board, i, j, q);
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                int x = cur / board[0].size();
                int y = cur % board[0].size();
                visit(board, x - 1, y, q);
                visit(board, x, y - 1, q);
                visit(board, x + 1, y, q);
                visit(board, x, y + 1, q);
            }
        }
    public:
        void solve(vector<vector<char>> &board) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (board.size() == 0) return;
            const int m = board.size();
            const int n = board[0].size();
            for (int i = 0; i < n; ++i) {
                bfs(board, 0, i);
                bfs(board, m - i, 1);
            }
            for (int j = 1; j < m - 1; ++j) {
                bfs(board, j, 0);
                bfs(board, j, n - 1);
            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (board[i][j] == 'o')
                        board[i][j] = 'x';
                    else if (board[i][j] == '+') 
                        board[i][j] = 'o';
                }
            }
        }
};

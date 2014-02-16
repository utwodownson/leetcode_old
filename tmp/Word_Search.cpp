/* Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, 
 * where "adjacent" cells are those horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 * For example,
 * Given board =
 * [
 *   ["ABCE"],
 *   ["SFCS"],
 *   ["ADEE"]
 * ]
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 */
int dirx[] = { -1, 1, 0, 0};
int diry[] = { 0, 0, -1, 1};
class Solution {
    bool dfs(const vector<vector<char> > &board, const string &word, int index, int x, int y,
            vector<vector<bool> > &visited) {
        if (index == word.size()) 
            return true;

        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false;
        if (visited[x][y]) return false;
        if (board[x][y] != word[index]) return false;

        bool ret = false;

        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) 
            ret = ret || dfs(board, word, index + 1, x + dirx[i], y + diry[i], visited);
        visited[x][y] = false;
        return ret;
    }
    public:
    bool exist(vector<vector<char> > &board, string word) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                if (dfs(board, word, 0, i, j, visited))
                    return true;
        return false;
    }
};

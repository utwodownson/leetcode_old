/* Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * For example,
 * Given n = 3,
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 * ]
 */
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
int n;
vector<vector<int> > ans;

class Solution {
    void dfs(int r, int c, int p, int number){
        ans[r][c] = number;
        for (int i = 0; i < 4; ++i) {
            int nowp = p + i & 3;
            int nr = r + dx[nowp];
            int nc = c + dy[nowp];
            if (nr >= 0 && nr < n)
                if (nc >= 0 && nc < n)
                    if (ans[nr][nc] == 0) {
                        dfs(nr, nc, nowp, number + 1);
                        break;
                    }
        }
    }
    public:
    vector<vector<int> > generateMatrix(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ans.clear();
        if(n <= 0) return ans;
        ::n = n;
        ans.resize(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ans[i].push_back(0);
        dfs(0, 0, 0, 1);
        return ans;
    }
};

/*  up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */
/*  up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */
class Solution {
        bool check(int y, int n, vector<int> &a) {
            for(int i = 0; i < n; i++)
                if (abs(i - n) == abs(y - a[i]))
                    return false;
            return true;
        }

        void dfs(int dep, int maxDep, vector<int> &a, 
                vector<bool> &canUse, vector<vector<string> > &ans) {
            if (dep == maxDep) {
                vector<string> ret;
                for (int i = 0; i < maxDep; ++i) {
                    string s;
                    for (int j = 0; j < a[i]; ++j) 
                        s += '.';
                    s += 'Q';
                    for (int j = 0; i < maxDep - (a[i] + 1); ++j) 
                        s += '.';
                    ret.push_back(s);
                }
                ans.push_back(ret);
                return;
            }

            for(int i = 0; i < maxDep; i++)
                if (canUse[i] && check(i, dep, a)) {
                    canUse[i] = false;
                    a[dep] = i;
                    dfs(dep + 1, maxDep, a, canUse, ans);
                    canUse[i] = true;             
                }
        }
    public:
        vector<vector<string> > solveNQueens(int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<vector<string> > ans;
            vector<int> a(n, 0);
            vector<bool> canUse(n, true);
            dfs(0, n, a, canUse, ans);
            return ans;
        }
};


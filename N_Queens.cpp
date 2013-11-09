/*  up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */
class Solution {
    bool check(int y, int n, vector<int> &a) {
        for (int i = 0; i < n; i++)
            if (abs(i - n) == abs(y - a[i]))
                return false;
        return true;
    }

    void solve(int dep, int maxDep, vector<bool> &canUse, vector<int> &a, vector<vector<string> > &ret) {
        if (dep == maxDep) {
            vector<string> ans;
            for (int i = 0; i < maxDep; i++) {
                string s;
                for (int j = 0; j < a[i]; j++)
                    s += '.';
                s += 'Q';
                for (int j = 0; j < maxDep - (a[i] + 1); j++)
                    s += '.';
                ans.push_back(s);
            }
            ret.push_back(ans);
            return;
        }

        for (int i = 0; i < maxDep; i++)
            if (canUse[i] && check(i, dep, a)) {
                canUse[i] = false;
                a[dep] = i;
                solve(dep + 1, maxDep, canUse, a, ret);
                canUse[i] = true;             
            }
    }

    public:
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string> > ret;
        vector<bool> canUse(n, true);
        vector<int> a(n, 0);
        solve(0, n, canUse, a, ret);
        return ret;
    }
};



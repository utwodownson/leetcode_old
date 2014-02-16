/*  up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */
/*  up for N-Queens problem.
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 */
class Solution {
        int ret;
        bool check(int y, int n, vector<int> &a) {
            for(int i = 0; i < n; i++)
                if (abs(i - n) == abs(y - a[i]))
                    return false;
            return true;
        }

        void dfs(int dep, int maxDep, vector<int> &a, vector<bool> &canUse) {
            if (dep == maxDep) {
                ret++;            
                return;
            }

            for(int i = 0; i < maxDep; i++)
                if (canUse[i] && check(i, dep, a)) {
                    canUse[i] = false;
                    a[dep] = i;
                    dfs(dep + 1, maxDep, a, canUse);
                    canUse[i] = true;             
                }
        }
    public:
    int totalNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ret = 0;
        vector<int> a(n, 0);
        vector<bool> canUse(n, true);
        dfs(0, n, a, canUse);
        return ret;
    }
};


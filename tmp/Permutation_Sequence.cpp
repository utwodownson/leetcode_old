/* The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
        int fib(int x) {
            int ret = 1;
            for(int i = 1; i <= x; ++i)
                ret = ret * i;
            return ret;
        }

        void dfs(int n, int *ans, bool *flag, int step, int k) {
            if (step <= 0) return ;
            int now = 0;
            for (int i = 1; i <= n; ++i)
                if (!flag[i]) {
                    now++;
                    if (now * fib(step - 1) >= k) {
                        ans[n - step + 1] = i;
                        flag[i] = true;
                        dfs(n, ans, flag, step - 1, k - (now - 1) * fib(step - 1));
                        break;
                    }
                }
        }
    public:
        string getPermutation(int n, int k) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int ans[n + 1];
            bool flag[n + 1];
            memset(flag, 0x00, sizeof(flag));
            dfs(n, ans, flag, n, k);
            string ret = "";
            for (int i = 1; i <= n; ++ i)
                ret += '0' + ans[i];
            return ret;
        }
};

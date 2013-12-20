/* Given n, how many structurally unique BST's 
 * (binary search trees) that store values 1...n?
 */
class Solution {
    public:
        int numTrees(int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> f(n + 1, 0);
            f[0] = f[1] = 1;
            for (int i = 2; i <= n; ++i) 
                for (int j = 1; j <= i; ++j)
                    f[i] += f[j - 1] * f[i - j];
            return f[n];
        }
};

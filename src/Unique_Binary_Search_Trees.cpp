/* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?  */
class Solution {
    public:
        int numTrees(int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> a(n + 1, 0);
            a[0] = 1;
            a[1] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j < i; j++)
                    a[i] += a[j] * a[i - j - 1];
            }
            return a[n];
        }
};

/* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
 * For example, given
 * s = "leetcode",
 * dict = ["leet", "code"].
 * Return true because "leetcode" can be segmented as "leet code".
 */
class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> &dict) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            string tmp = '#' + s;
            int n = tmp.length();
            vector<bool> d(n, false);

            d[0] = true;

            for (int i = 1; i < n; ++i) {
                for (int j = 0; j < i; ++j) {
                    d[i] = d[j] && dict.find(tmp.substr(j + 1, i - j)) != dict.end();
                    if (d[i]) break;
                }
            }
            return d[n - 1];
        }
};

/* You are given a string, S, and a list of words, L, 
 * that are all of the same length. 
 * Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 * You should return the indices: [0,9].
 * (order does not matter).
 */
class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            map<string, int> word, curStr;
            vector<int> ret;
            int n = L.size(), m = L[0].size(), i, j;

            if (!n || n * m > S.size()) return ret;

            for (i = 0; i < n; ++i) 
                ++word[L[i]];

            for (i = 0; i <= S.size() - n * m; ++i) {
                curStr.clear();
                for (j = 0; j < n; ++j) {
                    string t = S.substr(i + j * m, m);
                    if (word.find(t) == word.end()) break;
                    ++curStr[t];
                    if (curStr[t] > word[t]) break;
                }
                if (j == n) 
                    ret.push_back(i);
            }
            return ret;
        }
};

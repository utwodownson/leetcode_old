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
            map<string, int> word;
            map<string, int> curStr;
            vector<int> ret;
            int N = L.size();
            if (N <= 0) 
                return ret;
            for (int i = 0; i < L.size(); ++i) 
                ++word[L.at(i)];

            int M = L.at(0).size();
            int i, j;
            for (i = 0; S.size() >= N * M && i <= S.size() - N * M; ++i) {
                curStr.clear();
                for (j = 0; j < N; ++j) {
                    string t = S.substr(i + j * M, M);
                    if (word.find(t) == word.end()) 
                        break;
                    ++curStr[t];
                    if (curStr[t] > word[t])
                        break;
                }
                if (j == N)
                    ret.push_back(i);
            }
            return ret;
        }
};

/* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
 * Return all such possible sentences.
 * For example, given
 * s = "catsanddog",
 * dict = ["cat", "cats", "and", "sand", "dog"].
 * A solution is ["cats and dog", "cat sand dog"].
 */
class Solution {
    bool findWord(const char* a, int cur, int len, unordered_set<string> &dict, vector<string>& split, vector<string>& res) {
        if (cur == len) {
            string tmp = split[0];
            int lensp = split.size();
            for (int i = 1; i < lensp; i++) {
                tmp += " ";
                tmp += split[i];
            }   
            res.push_back(tmp);
        }   
        int i = 0;
        int size = split.size();
        for(i = cur+1; i <= len; i++) {
            string tmp = string(a+cur, i-cur);
            if (dict.find(tmp) != dict.end()) {
                split.resize(size);
                split.push_back(tmp);
                findWord(a, i, len, dict, split, res);
            }   
        }   
    }
    public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int lens = s.size();
        vector<string> res;
        vector<string> split;

        vector<bool> wordB(s.length() + 1, false);
        wordB[0] = true;
        for (int i = 1; i < s.length() + 1; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (wordB[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    wordB[i] = true;
                    break;
                }   
            }   
        }   
        if (!wordB[s.length()]) return res;

        findWord(s.c_str(), 0, lens, dict, split, res);
        return res;
    }
};

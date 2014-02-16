/* Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
class Solution {
    void dfs(string a[], string &digits, int deep, string &result, vector<string> &set) {
        if (deep == digits.size()) {
            set.push_back(result);
            return;
        }

        int curDig = digits[deep] - 49;
        for (int i = 0; i < a[curDig].size(); ++i) {
            result.push_back(a[curDig][i]);
            dfs(a, digits, deep + 1, result, set);
            result.resize(result.size() - 1);
        }
    }
    public:
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string a[] = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> set;
        string seq;
        dfs(a, digits, 0, seq, set);
        return set; 
    }
};


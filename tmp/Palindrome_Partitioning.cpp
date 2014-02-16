/* Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 * For example, given s = "aab",
 * Return
 * [
 *   ["aa","b"],
 *   ["a","a","b"]
 * ]
 */
class Solution {
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void dfs(string &s, int start, vector<string> &output, vector<vector<string> > &result) {
        if (start == s.size()) {
            result.push_back(output);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                output.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, output, result);
                output.pop_back();
            }
        }
    }
    public:
    vector<vector<string>> partition(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string> > result;
        vector<string> output;
        dfs(s, 0, output, result);
        return result;
    }
};

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return
 * 
 *   [
 *    ["aa","b"],
 *    ["a","a","b"]
 *   ]
 */

class Solution {
    public:
    vector<vector<string>> ans;
    bool is
        vector<vector<string>> partition(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> str;
            str.clear();
            ans.clear();
            dfs(s, 0, str);
            return ans; 
        }
};

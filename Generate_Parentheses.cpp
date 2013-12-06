/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */
class Solution {
    void dfs(string s, int left, int right, vector<string> &vc, int n){
        if (left == n && right == n){
            vc.push_back(s);
            return;
        }

        if (left < n)
            dfs(s + '(', left + 1, right, vc, n);

        if (right < left)
            dfs(s + ')', left, right + 1, vc, n);
    }
    public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vc;
        dfs("", 0, 0, vc, n);
        return vc;
    }
};


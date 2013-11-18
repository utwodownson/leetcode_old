/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * For example, given n = 3, a solution set is:
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */
class Solution {
    void dfs(string s, int left, int right, vector<string> &vc){
        if(left == 0 && right == 0){
            vc.push_back(s);
            return;
        }

        if(left > 0)
            dfs(s + '(', left - 1, right, vc);

        if(right - 1 >= left)
            dfs(s + ')', left, right - 1, vc);
    }
    public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vc;
        vc.clear();
        dfs("", n, n, vc);
        return vc;
    }
};

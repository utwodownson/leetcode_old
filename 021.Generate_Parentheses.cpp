/**
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 * 
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 * 
 */

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> ret;
            vector<char> str(2 * n + 1, 0);
            int k = 0, m = 0;
            while (k >= m) {
                while (k + m < 2 * n) {
                    if (k < n) {
                        str[k + m] = '(';
                        k++;
                    } else {
                        str[k + m] = ')';
                        m++;
                    }
                }
                ret.push_back(str.data());
                while (k > 0 && (k == m || str[k + m] == ')')) {
                    if (str[k + m - 1] == '(') 
                        k--;
                    else 
                        m--;
                }
                str[k + m] = ')';
                m++;
            }
            return ret;
        }
};

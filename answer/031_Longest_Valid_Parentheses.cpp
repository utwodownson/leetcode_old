/**
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * 
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * 
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */

class Solution {
    public:
        int longestValidParentheses(string s) {
            int max_length = 0;
            int valid = 0;
            int start = -1;
            for (size_t i = 0; i < s.length(); i++) {
                if (s[i] == '(') {
                    valid++;
                } else if (s[i] == ')') {
                    valid--;
                }
                if (valid == 0) {
                    if (i - start > max_length) {
                        max_length = i - start;
                    }
                } else if (valid < 0) {
                    start = i;
                    valid = 0;
                }
            }
            start = s.length();
            valid = 0;
            for (int i = s.length() - 1; i >= 0; i--) {
                if (s[i] == ')') {
                    valid++;
                } else if (s[i] == '(') {
                    valid--;
                }
                if (valid == 0) {
                    if (start - i > max_length) {
                        max_length = start - i;
                    }
                } else if (valid < 0) {
                    start = i;
                    valid = 0;
                }
            }
            return max_length;
        }
};

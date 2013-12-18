/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
class Solution {
    public:
        int longestValidParentheses(string s) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            stack<int> lefts;
            int ans = 0, last = -1;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(') lefts.push(i);
                else {
                    if (!lefts.empty()) {
                        lefts.pop();
                        ans = max(ans, i - (lefts.empty() ? last : lefts.top()));
                    } else 
                        last = i;
                }
            }
            return ans;
        }
};


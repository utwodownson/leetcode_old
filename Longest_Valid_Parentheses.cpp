/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
class Solution {
    public:
        int longestValidParentheses(string s) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            stack<int> st;
            int ans = 0, last = -1;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(') 
                    st.push(i);
                else {
                    if (!st.empty()) {
                        st.pop();
                        ans = max(ans, i - (st.empty() ? last : st.top()));
                    } else 
                        last = i;
                }
            }
            return ans;
        }
};


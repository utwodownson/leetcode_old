/* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
class Solution {
    public:
        int longestValidParentheses(string s) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            const char *str = s.c_str();
            const char *p = str;
            stack<const char*> st;
            int nMax = 0;

            while (*p != '\0') {
                if (*p == '(')
                    st.push(p);
                else {
                    if (!st.empty() && *st.top() == '(') {
                        st.pop();
                        nMax = max(nMax, p - (st.empty() ? str - 1 : st.top()));
                    } else {
                        st.push(p);
                    }
                }
                p++;
            }
            return nMax;
        }
};


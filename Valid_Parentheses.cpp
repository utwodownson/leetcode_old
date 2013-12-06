/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * 
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
class Solution {
    public:
        bool isValid(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            stack<char> buf;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != ')' && s[i] != ']' && s[i] != '}')
                    buf.push(s[i]);
                else {
                    if (buf.empty()) return false;
                    if (s[i] == ')' && buf.top() != '(') return false;
                    else if (s[i] == ']' && buf.top() != '[') return false;
                    else if (s[i] == '}' && buf.top() != '{') return false;
                    else buf.pop();
                }
            }
            return buf.empty();
        }
};


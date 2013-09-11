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
            vector<char> tmp;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    tmp.push_back(s[i]);
                } else if (s[i] == ')') {
                    if (tmp.empty() || tmp.back() != '(')
                        return false;
                    tmp.pop_back();
                } else if (s[i] == ']') {
                    if (tmp.empty() || tmp.back() != '[') 
                        return false;
                    tmp.pop_back();
                } else if (s[i] == '}') {
                    if (tmp.empty() || tmp.back() != '{') 
                        return false;
                    tmp.pop_back();
                }
            }
            return tmp.empty();
        }
};

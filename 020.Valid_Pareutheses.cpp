#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int len = s.length();
            char *stack = (char *) malloc(sizeof(char) * len);
            int top = -1;
            for (int i = 0; i < len; ++i) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    stack[++top] = s[i];
                } else if (s[i] == '}') {
                    if (top < 0 || stack[top--] != '{') return false;
                } else if (s[i] == ')') {
                    if (top < 0 || stack[top--] != '(') return false;
                } else if (s[i] == ']') {
                    if (top < 0 || stack[top--] != '[') return false;
                } else {
                    return false;
                }
            }
            if (stack) free(stack);
            if (top == -1) return true;
        }
};

int main(void) {
    Solution s;
    string str;
    while (cin >> str) {
        cout << (s.isValid(str) ? "true" : "false") << endl;
    }
    return 0;
}


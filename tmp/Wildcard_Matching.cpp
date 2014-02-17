/* Implement wildcard pattern matching with support for '?' and '*'.*/
class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            bool flag = false;
            const char *str, *ptr;
            for (str = s, ptr = p; *str != '\0'; ++str, ++ptr) {
                if (*ptr == '?') continue;
                else if (*ptr == '*') {
                    flag = true;
                    for (s = str, p = ptr; *ptr == '*'; ++ptr) ++p;
                    if (*ptr == '\0') return true;
                    --str; --ptr;
                } else if (*str != *ptr) {
                    if (!flag) return false;
                    ++s;
                    str = s - 1;
                    ptr = p - 1;
                } 
            }
            while (*ptr == '*') ++ptr;
            return *ptr == '\0';
        }
};

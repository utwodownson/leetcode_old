/* Implement wildcard pattern matching with support for '?' and '*'.*/
class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            const char *star = NULL;
            const char *ss = s;
            while (*s) {
                if ((*p == '?') || (*p == *s)) { 
                    ++s; 
                    ++p; 
                } else if (*p == '*') { 
                    star = p++;
                    ss = s;
                } else if (star) {
                    p = star + 1;
                    s = ++ss;
                } else {
                    return false;
                }
            }
            while (*p == '*') ++p;
            return !*p;
        }
};

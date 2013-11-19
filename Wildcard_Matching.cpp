/* Implement wildcard pattern matching with support for '?' and '*'.*/
class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            bool flag = false;
            const char *str, *ptr;

            for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
                switch (*ptr) {
                    case '?' :
                        break;
                    case '*' :
                        flag = true;
                        s = str, p = ptr;
                        while (*p == '*') p++;
                        if (*p == '\0') return true;
                        str = s - 1;
                        ptr = p - 1;
                        break;
                    default :
                        if (*str != *ptr) {
                            if (!flag) return false;
                            s++;
                            str = s - 1;
                            ptr = p - 1;
                        }
                }
            }
            while (*ptr == '*') ptr++;
            return (*ptr == '\0');
        }
};

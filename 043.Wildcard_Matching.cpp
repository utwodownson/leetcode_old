/**
 * Implement wildcard pattern matching with support for '?' and '*'.
 * 
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") ? false
 * isMatch("aa","aa") ? true
 * isMatch("aaa","aa") ? false
 * isMatch("aa", "*") ? true
 * isMatch("aa", "a*") ? true
 * isMatch("ab", "?*") ? true
 * isMatch("aab", "c*a*b") ? false
 */

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if (s == 0 || p == 0) {
                return s == p;
            }

            int i = 0, j = 0, ss = 0, sp = 0;
            int ls = strlen(s);
            int lp = strlen(p);
            bool any = false;
            while (i <= ls || j <= lp) {
                if (p[j] == '*') {
                    any = true;
                    ss = i;
                    sp = j;
                    i--;
                } else if (s[i] == 0 || (p[j] != '?' && p[j] != s[i])) {                
                    if (any && j - sp + ss <= ls) {
                        j = sp;
                        i = ss++;
                    } else {
                        break;
                    }
                }
                i++;
                j++;
            }
            return s[i] == p[j];
        }
};

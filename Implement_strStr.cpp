/* Implement strStr().
 * Returns a pointer to the first occurrence of needle in haystack, 
 * or null if needle is not part of haystack.
 */
class Solution {
    public:
        char *strStr(char *haystack, char *needle) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if (!haystack || !needle) return NULL;
            int ln = strlen(haystack), rn = strlen(needle);
            for (int i = 0; i <= ln - rn; ++i) {
                int j = 0;
                for (j = 0; j < rn && haystack[i + j] == needle[j]; ++j);
                if (j >= rn) return haystack + i;
            }
            return NULL;
        }
};

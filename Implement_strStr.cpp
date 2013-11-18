/* Implement strStr().
 * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 */
class Solution {
    public:
        char *strStr(char *haystack, char *needle) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if (haystack == 0 || needle == 0) return 0;

            int len1 = strlen(haystack);
            int len2 = strlen(needle);

            for (int i = 0; i <= len1 - len2; ++i) {
                int j = 0;
                for ( ; j < len2 && haystack[i + j] == needle[j]; ++j);
                if (j == len2) 
                    return haystack + i;
            }
            return 0;
        }
};

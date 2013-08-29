/*
 * Implement strStr().
 * 
 * Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
 */
class Solution {
    public:
        char *strStr(char *haystack, char *needle) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            /*
            if (*needle) {
                while (*haystack) {
                    for (int n = 0; n < strlen(needle) && *(haystack + n) == *(needle + n); ++n) {
                        if (! *(needle + n + 1)) 
                            return (char *) haystack;
                    }
                    haystack++;
                }
                return NULL;
            } else {
                return (char *) haystack;
            }
             */
            if (haystack == 0 || needle == 0) 
                return 0;

            int len1 = strlen(haystack);
            int len2 = strlen(needle);

            for (int i = 0; i <= len1 - len2; i++) {
                int j = 0;
                for ( ; j < len2 && haystack[i + j] == needle[j]; j++) { } // must have {}
                if (j == len2) 
                    return haystack + i;
            }
            return 0;
        }
};

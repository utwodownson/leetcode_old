class Solution {
    public:
        char *strStr(char *haystack, char *needle) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (haystack == NULL) return NULL;
            int len_a = strlen(haystack);
            int len_b = strlen(needle);
            if (len_a < len_b) return NULL;
            for (int i = 0; i < len_a - len_b + 1; ++i) {
                int j = 0;
                for ( ; j < len_b && haystack[i + j] == needle[j]; ++j);
                if (j == len_b) return haystack + i;
            }
            return NULL;
        }
};

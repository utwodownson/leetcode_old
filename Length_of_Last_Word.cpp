/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 * Note: A word is defined as a character sequence consists of non-space characters only.
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */
class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            int ans = 0, len = 0;
            for (const char *p = s; *p != '\0'; ++p) 
                *p == ' ' ? len = 0 : ans = ++len;
            return ans;
        }
};

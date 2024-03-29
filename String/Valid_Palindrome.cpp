/* Given a string, determine if it is a palindrome, 
 * considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * Note:
 * Have you consider that the string might be empty? 
 * This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
class Solution {
    public:
        bool isPalindrome(string s) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int i = 0, j = s.length() - 1;
            while (i < j) {
                if (!isalnum(s[i])) ++i;
                if (!isalnum(s[j])) --j;
                if (isalnum(s[i]) && isalnum(s[j])) {
                    if (toupper(s[i]) != toupper(s[j])) return false;
                    else { ++i; --j; }
                }
            }
            return true;
        }
};

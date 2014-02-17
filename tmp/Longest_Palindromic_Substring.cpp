/* Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
 */
class Solution {
    public:
        string longestPalindrome(string s) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            string subs = "";
            int len = s.length(), max_half = 0;

            for (int i = 0; i < len - max_half; ++i) {
                int j, k;

                for (k = i, j = i + 1; 0 <= k && j < len && s[k] == s[j]; --k, ++j);
                if (subs.length() < j - k - 1) {
                    max_half = j - i - 1;
                    subs = s.substr(k + 1, j - k - 1);
                }

                for (k = i - 1, j = i + 1; 0 <= k && j < len && s[k] == s[j]; --k, ++j);
                if (subs.length() < j - k - 1) {
                    max_half = j - i - 1;
                    subs = s.substr(k + 1, j - k - 1);
                }
            }
            return subs;
        }
};

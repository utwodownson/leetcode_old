/* Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, 
 * and there exists one unique longest palindromic substring.
 */
class Solution {
    public:
        string longestPalindrome(string s) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int max_half = 0;
            string substr = "";
            for (int i = 0; i < s.length() - max_half; ++i) {
                int j, k;
                for (j = i + 1, k = i; j < s.length() && k >= 0 && s[j] == s[k]; ++j, --k);
                
                if (substr.length() < j - k - 1) {
                    max_half = j - i - 1;
                    substr = s.substr(k + 1, j - k - 1);
                }

                for (j = i + 1, k = i - 1; j < s.length() && k >= 0 && s[j] == s[k]; ++j, --k);

                if (substr.length() < j - k - 1) {
                    max_half = j - i - 1;
                    substr = s.substr(k + 1, j - k - 1);
                }
            }
            return substr;
        }
};
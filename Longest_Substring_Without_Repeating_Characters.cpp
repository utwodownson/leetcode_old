/*
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<bool> hash(256, false);
            int maxl = 0, i = 0, j = 0, len = s.length();
            while (j < len) {
                while (j < len && !hash[s[j]])
                    hash[s[j++]] = true;

                if (maxl < j - i)
                    maxl = j - i;

                while (s[i] != s[j])
                    hash[s[i++]] = false;

                ++j; ++i;
            }
            return maxl;
        }
};

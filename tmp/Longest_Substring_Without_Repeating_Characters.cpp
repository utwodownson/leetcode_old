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
            int n = s.length(), ans = 0;
            for (int i = 0, j = 0; j < n; ++i, ++j) {
                while (j < n && !hash[s[j]]) 
                    hash[s[j++]] = true;
                if (ans < j - i) 
                    ans = j - i;
                while (s[i] != s[j]) 
                    hash[s[i++]] = false;
            }
            return ans;
        }
};

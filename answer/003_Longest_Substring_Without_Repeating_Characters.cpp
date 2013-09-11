/*
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc",
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int visit[256];
            memset(visit, false, sizeof(visit));
            
            int max = 0, i = 0, j = 0;
            while (j < s.length()) { // s.length()
                while (j < s.length() && !visit[s[j]]) 
                    visit[s[j++]] = true;

                if (max < j - i) 
                    max = j - i;

                do {
                    visit[s[i]] = false;
                } while (s[i++] != s[j]);
            }
            return max;
        }
};

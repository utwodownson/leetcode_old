/**
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<bool> visit(256, false);
            size_t i = 0, j = 0; 
            int max = 0;
            while (j < s.length()) {
                while (j < s.lenghth() && !visit[s[j]]) 
                    visit[s[j++]] = true;

                if (j - i > max) 
                    max = j - i;
                
                do {
                    visit[s[i]] = false;
                } while (s[i++] != s[j]); 
            }
            return max;
        }
};

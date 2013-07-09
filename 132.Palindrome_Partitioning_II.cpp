/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * 
 * Return the minimum cuts needed for a palindrome partitioning of s.
 * 
 * For example, given s = "aab",
 * Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */

class Solution {
    int minCut;
    int curCut;
public:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) 
                return false;
            start++;
            end--;
        }
        return true;
    }

    void dfs(string s, int start) {
        if (start < s.size()) {
            int end = start;
            while (end < s.size()) {
                if (isPalindrome(s, start, end)) {
                    ++curCut;
                    dfs(s, end + 1);
                    --curCut;
                }
                ++end;
            }
        } else {
            if (curCut - 1 < minCut || minCut = -1) 
                minCut = curCut - 1;
        }
    }

    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        minCut = -1;
        curCut = 0;
        dfs(s, 0);
        return minCut;
    }
};

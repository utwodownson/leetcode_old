/**
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = 0, count1 = 1, count2 = 2;
        for (int i = 0; i < s.length(); ++i) {
            count = 0;
            if (s[i] >= '1' && s[i] <= '9')
                count = count1;
            if (i > 0 && ((s[i - 1] == '1' && s[i] >= '0' && s[i] <='9') || 
                (s[i - 1] == '2' && s[i] >= '0' && s[i] <='6')))
                count += count2;
            count2 = count1;
            count1 = count;
        }
        return count;
    }
};


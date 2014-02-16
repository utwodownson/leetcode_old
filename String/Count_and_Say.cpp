/* The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 */
class Solution {
    string count(string s) {
        int num = 0, len = s.length();
        string ans;
        for (int i = 0; i < len; ++i) {
            char c = s[i];
            for ( ; s[i] == c && i < len; ++i, ++num);
            while (num) {
                ans.push_back(num % 10 + '0');
                num /= 10;
            }
            ans.push_back(c);
            --i;
        }
        return ans;
    }
public:
    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string s = "1";
        while (--n) 
            s = count(s);
        return s;
    }
};

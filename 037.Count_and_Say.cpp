/**
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 */

class Solution {
    public:
        void count(string &s, int n) {
            string v;
            while (n) {
                v.push_back(n % 10 + '0');
                n /= 10;
            }
            for (int i = v.length() - 1; i >= 0; --i) 
                s.push_back(v[i]);
        }

        string countAndSay(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int cnt = 0; 
            string s = "1", t;
            while (--n) {
                t = s;
                s = "";
                for (int i = 0; i < t.length(); ++i) {
                    cnt = 1;
                    while (t[i] == t[i + 1]) {
                        i++;
                        cnt++;
                    }
                    count(s, cnt);
                    s.push_back(t[i]);
                }
            }
            return s;
        }
};

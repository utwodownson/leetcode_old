/*
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    int romanToInt(string s) {
        string name = "IVXLCDM";
        int value[] = { 1, 5, 10, 50, 100, 500, 1000 };

        int len = sizeof(value) / sizeof(int);
        int val = 0, last = 0;

        for (int i = 0; i < s.length(); ++i) {
            int v = value[name.find(s[i])];
            val = v <= last ? val + last : val - last;
            last = v;
        }
        return val + last;
    }
};

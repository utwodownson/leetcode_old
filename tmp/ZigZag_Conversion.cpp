/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */
class Solution {
    public:
        string convert(string s, int nRows) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int d = 2 * nRows - 2;
            int len = s.length();
            string res;
            if (d <= 0) d = 1;
            for (int i = 0; i < nRows; ++i) {
                for (int j = i, inc = j * 2; j < len; j += inc) {
                    if (inc < d)
                        inc = d - inc;
                    res.push_back(s[j]);
                }
            }
            return res;
        }
};

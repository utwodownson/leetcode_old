/*
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
    public:
        void appendNumToRoman(int num, string &roman, char symbols[]) {
            if (num == 0)
                return;
            if (num <= 3) {
                roman.append(num, symbols[0]);
            } else if (num == 4) {
                roman.append(1, symbols[0]);
                roman.append(1, symbols[1]);
            } else if (num <= 8) {
                roman.append(1, symbols[1]);
                roman.append(num - 5, symbols[0]);
            } else {
                roman.append(1, symbols[0]);
                roman.append(1, symbols[2]);
            }
        }
        string intToRoman(int num) {
            char symbol[9] = { 'I','V','X', 'L','C', 'D','M', 'v', 'x' };
            string roman = "";
            int scale = 1000;
            for (int i = 6; i >= 0 ; i -= 2) {
                int digit = num / scale;
                appendNumToRoman(digit, roman, symbol + i);
                num = num % scale;
                scale /= 10;
            }
            return roman;
        }
};
/*
string intToRoman (int num) {
    string ret;
    char *roman[4][10] = {
        { "" , "I" , "II", "III" , "IV" , "V", "VI" , "VII" , "VIII", "IX" },
        { "" , "X" , "XX", "XXX" , "XL" , "L", "LX" , "LXX" , "LXXX", "XC" },
        { "" , "C" , "CC", "CCC" , "CD" , "D", "DC" , "DCC" , "DCCC", "CM" },
        { "" , "M" , "MM", "MMM" , "" , "", "" , "" , "", "" }};
    int ind = 0;
    while (num > 0) {
        int c = num % 10;
        num /= 10;
        ret = string(roman[ind++][c]) + ret;
    }
    return ret;
}
*/

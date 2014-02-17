/*
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
class Solution {
    public:
        string intToRoman(int num) {
            string ret;
            char *roman[4][10] = {
                { "" , "I" , "II", "III" , "IV" , "V", "VI" , "VII" , "VIII", "IX" },
                { "" , "X" , "XX", "XXX" , "XL" , "L", "LX" , "LXX" , "LXXX", "XC" },
                { "" , "C" , "CC", "CCC" , "CD" , "D", "DC" , "DCC" , "DCCC", "CM" },
                { "" , "M" , "MM", "MMM" , "" , "", "" , "" , "", "" }
            };
            int ind = 0;

            while (num > 0) {
                int c = num % 10;
                num /= 10;
                ret = string(roman[ind++][c]) + ret;
            }
            return ret;
        }
};

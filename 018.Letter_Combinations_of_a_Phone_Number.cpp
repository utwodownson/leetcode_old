/**
 * Given a digit string, return all possible letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * 
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
class Solution {
    vector<string> ret;
    public:
        void recurComb(const char *in, vector<char>& out)
        {
            char startc[9] = "adgjmptw";
            startc[8] = 'z' + 1;
            if (*in == NULL) {
                out.push_back(0);
                ret.push_back(out.data());
                out.pop_back(); 
            } else if (*in == '1') {
                recurComb(in + 1, out);
            } else if (*in == '0') {
                out.push_back(' ');
                recurComb(in + 1, out);
                out.pop_back();
            } else {
                int p = *in - '2';
                for (int c = startc[p]; c < startc[p + 1]; ++c) {
                    out.push_back(c);
                    recurComb(in + 1, out);
                    out.pop_back();
                }
            }
        }
        vector<string> letterCombinations(string digits) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ret.clear();
            std::vector<char> out;
            recurComb(digits.c_str(), out);
            return ret; 
        }
};

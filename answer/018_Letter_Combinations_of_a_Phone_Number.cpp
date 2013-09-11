/*
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
    public:
        void Generater(string trans[], string& digits, 
                int deep, string& result, vector<string>& set)  
        {  
            if(deep == digits.size()) {  
                set.push_back(result);  
                return;  
            }  
            int curDig = digits[deep] - 48;  
            for(int i = 0; i < trans[curDig].size(); i++) {  
                result.push_back(trans[curDig][i]);  
                Generater(trans, digits, deep + 1, result, set);  
                result.resize(result.size() - 1);  
            }  
        }  
        vector<string> letterCombinations(string digits) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            string trans[] = {"", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  
            vector<string> set;      
            string seq; 
            Generater(trans, digits, 0, seq, set);  
            return set;  
        }
};

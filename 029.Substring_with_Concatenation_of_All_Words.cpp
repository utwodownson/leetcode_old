/**
 * You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
 * 
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 */

class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            map<string, int> words;  
            map<string, int> curStr;  
            for (int i = 0; i < L.size(); ++i)  
                ++words[L.at(i)];  
            int N = L.size();  
            vector<int> ret;  
            if(N <= 0)   return ret;  
            int M = L.at(0).size();  
            for(int i = 0; i <= (int)S.size()-N*M; ++i)  
            {  
                curStr.clear();  
                int j = 0;  
                for(j = 0; j < N; ++j)  
                {  
                    string w = S.substr(i+j*M, M);  
                    if(words.find(w) == words.end())  
                        break;  
                    ++curStr[w];  
                    if(curStr[w] > words[w])  
                        break;  
                }  
                if(j == N)  ret.push_back(i);  
            }  
            return ret;  
        }                                      
};

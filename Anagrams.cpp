/* Given an array of strings, return all groups of strings that are anagrams.
 * Note: All inputs will be in lower-case.
 */
class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            map<string, vector<string> > hash;
            for (int i = 0; i < strs.size(); ++i){
                string s(strs[i]);
                sort(s.begin(), s.end());
                hash[s].push_back(strs[i]);
            }

            vector<string> ret;
            for (map<string, vector<string> > :: iterator it = hash.begin();
                    it != hash.end(); ++it) {
                if ((it->second).size() > 1){
                    vector<string> &vs = it->second;
                    for (int i = 0; i < vs.size(); ++i)
                        ret.push_back(vs[i]);
                }
            }
            return ret;
        }
};

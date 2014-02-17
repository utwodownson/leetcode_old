/* Given two words (start and end), and a dictionary, 
 * find all shortest transformation sequence(s) from start to end, such that:
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 * 
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * Return
 *   [
 *       ["hit","hot","dot","dog","cog"],
 *       ["hit","hot","lot","log","cog"]
 *   ]
 * Note:
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 */
string start, end;
unordered_map<string, int> lev;
void dfs(string now, vector<string> & stk, vector<vector<string> > & ret){
    if(now == start){
        vector<string> tmp(stk);
        tmp.push_back(now);
        reverse(tmp.begin(), tmp.end());
        ret.push_back(tmp);
        return ;
    }
    stk.push_back(now);
    for(int i = 0; i < now.size(); ++ i)
        for(char c = 'a'; c <= 'z'; ++ c){
            string next(now);
            next[i] = c;
            if(next == now)
                continue;
            if(lev.find(next) != lev.end() && lev[next] == lev[now] - 1){
                dfs(next, stk, ret);
            }
        }
    stk.pop_back();
}
class Solution {
    public:
        vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<string> > ret;
            if(start == end){
                ret.resize(1);
                ret[0].push_back(start);
                return ret;
            }
            ::start = start;
            ::end = end;
            lev.clear();
            queue<string> q;
            lev[start] = 0;
            q.push(start);
            while(!q.empty()){
                string now = q.front();
                q.pop();
                if(now == end)
                    continue;
                for(int i = 0; i < now.size(); ++ i)
                    for(char c = 'a'; c <= 'z'; ++ c){
                        string next(now);
                        next[i] = c;
                        if(next == end || dict.find(next) != dict.end())
                            if(lev.find(next) == lev.end()){
                                lev[next] = lev[now] + 1;
                                q.push(next);
                            }
                    }
            }
            vector<string> stk;
            dfs(end, stk, ret);
            return ret;
        }
};

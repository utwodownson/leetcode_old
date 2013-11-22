/* Given an absolute path for a file (Unix-style), simplify it.
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */
class Solution {
    public:
        string simplifyPath(string path) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            vector<string> st;
            for (int i = 0, j = 0; i <= path.length(); i++) {
                if (path[i] == '/' || path[i] == 0) {
                    string dir = path.substr(j, i - j);
                    j = i;
                    if (dir.empty() || dir == "/." || dir == "/") continue;
                    if (dir == "/..") {
                        if (!st.empty()) 
                            st.pop_back();
                    } else {
                        st.push_back(dir);
                    }
                }
            }

            string ret;
            for (int i = 0; i < st.size(); i++) 
                ret = ret + st[i];

            return ret.empty() ? "/" : ret;
        }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode *root) {
            stack<TreeNode *> st;
            vector<int> ans;
            TreeNode *p = root, *tmp = 0;
            while (p || !st.empty()) {
                if (p) {
                    st.push(p);
                    p = p->left;
                } else {
                    TreeNode *t = st.top();
                    if (!t->right || t->right == tmp) {
                        ans.push_back(t->val);
                        st.pop();
                        tmp = t;
                    } else 
                        p = t->right;
                }
            }
            return ans;
        }
};

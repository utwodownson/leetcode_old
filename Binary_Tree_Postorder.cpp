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
            stack<TreeNode *> s;
            vector<int> ans;
            for (TreeNode *p = root, *tmp = 0; p || !s.empty(); ) {
                if (p) {
                    s.push(p);
                    p = p->left;
                } else {
                    TreeNode *t = s.top();
                    if (!t->right || t->right == tmp) {
                        ans.push_back(t->val);
                        s.pop();
                        tmp = t;
                    } else 
                        p = t->right;
                }
            }
            return ans;
        }
};

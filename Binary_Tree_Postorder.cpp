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
            TreeNode *p = root, *pre = NULL;  
            while (!s.empty() || p){
                if (p) {
                    s.push(p);
                    p = p->left;
                } else {
                    TreeNode *t = s.top();
                    if (!t->right || t->right == pre) {
                        ans.push_back(t->val);
                        s.pop();
                        pre = t;
                    } else 
                        p = t->right;  
                }
            }
            return ans;
        }
};

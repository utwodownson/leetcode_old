/* Given a binary tree, return the preorder traversal of its nodes' values.
 * For example:
 * Given binary tree {1,#,2,3},
  1
   \
    2
   /
  3
 * return [1,2,3].
 * Note: Recursive solution is trivial, could you do it iteratively?
 */
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
        vector<int> preorderTraversal(TreeNode *root) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            vector<int> ans;
            TreeNode *p = root;
            stack<TreeNode *> s;
            if (p) s.push(p);

            while (!s.empty) {
                p = s.top();
                s.pop();
                ans.push_back(p->val);
                if (p->right) s.push(p->right);
                if (p->left) s.push(p->left);
            }
            return ans;
        }
};

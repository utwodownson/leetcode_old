/* Given a binary tree, return the inorder traversal of its nodes' values.
 * For example:
 * Given binary tree {1,#,2,3},
 *  1
 *   \
 *    2
 *   /
 *  3
 * return [1,3,2].
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
        vector<int> inorderTraversal(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            stack<TreeNode *> s;
            vector<int> ans;
            for (TreeNode *p = root; p || !s.empty(); ) {
                if (p) {
                    s.push(p);
                    p = p->left;
                } else {
                    p = s.top(); s.pop();
                    ans.push_back(p->val);
                    p = p->right;
                }
            }
            return ans;
        }
};

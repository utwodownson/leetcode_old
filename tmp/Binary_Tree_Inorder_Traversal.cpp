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
            stack<TreeNode *> st;
            vector<int> ans;
            TreeNode *p = root;
            while (p || !st.empty()) {
                if (p) {
                    st.push(p);
                    p = p->left;
                } else {
                    p = st.top(); st.pop();
                    ans.push_back(p->val);
                    p = p->right;
                }
            }
            return ans;
        }
};

/* Given a binary tree, flatten it to a linked list in-place. */
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
        void flatten(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            stack<TreeNode *> st;
            TreeNode *p = 0;
            while (root || !st.empty()) {
                while (root) {
                    p = root;
                    st.push(root);
                    root = root->left;
                }
                if (!st.empty()) {
                    root = st.top();
                    st.pop();
                    if (p != root) {
                        p->right = root->right;
                        root->right = root->left;
                        root->left = 0;
                    }
                    root = p->right;
                }
            }
        }
};

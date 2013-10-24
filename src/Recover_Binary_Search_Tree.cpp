/* Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
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
        void recoverTree(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<TreeNode*> st;

            TreeNode *pre = 0, *first = 0, *second = 0;
            while (root || !st.empty()) {
                while (root) {
                    st.push_back(root);
                    root = root->left;
                }
                root = st.back();
                st.pop_back();
                if (pre && pre->val > root->val) {
                    if (first) {
                        swap(first->val, root->val);
                        return;
                    }
                    first = pre;
                    second = root;
                }
                pre = root;
                root = root->right;
            }
            if (first && second) {
                swap(first->val, second->val);
            }
        }
};

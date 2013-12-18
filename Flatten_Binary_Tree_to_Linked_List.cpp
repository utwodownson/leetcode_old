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
            if (!root) return;

            flatten(root->left);
            flatten(root->right);

            if (!root->left) return;

            TreeNode *p = 0;
            for (p = root->left; p->right; p = p->right);
            p->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
};

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
            stack<TreeNode *> s;
            TreeNode *pre = 0, *first = 0, *second = 0;
            while (root || !s.empty()) {
                if (root) {
                    s.push(root);
                    root = root->left;
                } else {
                    root = s.top(); s.pop();
                    if (pre && root->val < pre->val) {
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
            }
            if (first && second) swap(first->val, second->val);
        }
};

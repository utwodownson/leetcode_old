/* Given a binary tree, check whether it is a mirror of itself 
 * (ie, symmetric around its center). 
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
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && 
            isSymmetric(left->left, right->right) &&
            isSymmetric(left->right, right->left);
    }
    public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return root ? isSymmetric(root->left, root->right) : true;
    }
};

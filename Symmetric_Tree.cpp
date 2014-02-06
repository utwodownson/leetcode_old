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
        if (!left || !right) return left == right;
        if (left->val != right->val) return false;
        if (!isSymmetric(left->left, right->right)) return false;
        if (!isSymmetric(left->right, right->left)) return false;
        return true;
    }
    public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return root ? isSymmetric(root->left, root->right) : true;
    }
};

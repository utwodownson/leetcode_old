/* Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
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
        bool isValidBST(TreeNode *root, int *minval, int *maxval) {
            if (!root) return true;
            return (!minval || root->val > *minval) && 
                   (!maxval || root->val < *maxval) && 
                   isValidBST(root->left, minval, &root->val) && 
                   isValidBST(root->right, &root->val, maxval);
        }
    public:
        bool isValidBST(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            return traverseBST(root, 0, 0);
        }
};

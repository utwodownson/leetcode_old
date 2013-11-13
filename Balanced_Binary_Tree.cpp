/* Given a binary tree, determine if it is height-balanced.
 * For this problem, 
 * a height-balanced binary tree is defined as a binary tree 
 *in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root, int *h) {
        int h1 = 0, h2 = 0;
        if (root) {
            if (!isBalanced(root->left, &h1)) return false;
            if (!isBalanced(root->right, &h2)) return false;
            if (abs(h1 - h2) > 1) return false;

            *h = (h1 > h2 ? h1 : h2) + 1;
        }
        return true;
    }
    public:
    bool isBalanced(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int h = 0;
        return isBalanced(root, &h);
    }
};

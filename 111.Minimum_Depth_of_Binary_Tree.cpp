/**
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
        int minDepth(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (root) {
                int ld = minDepth(root->left);
                int rd = minDepth(root->right);
                return (ld > 0 && rd > 0 ? min(ld, rd) : max(ld, rd)) + 1;
            } else {
                return 0;
            }
        }
};
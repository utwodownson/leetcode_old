/* Given a binary tree, find its minimum depth.
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
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (!root) return 0;
            int lh = minDepth(root->left);
            int rh = minDepth(root->right);
            return (lh > 0 && rh > 0 ? min(lh, rh) : max(lh, rh)) + 1;
        }
};

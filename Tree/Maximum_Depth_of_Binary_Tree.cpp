/* Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
        int maxDepth(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (!root) return 0;
            int left_height = maxDepth(root->left);
            int right_height = maxDepth(root->right);
            return left_height > right_height ? left_height + 1 : right_height + 1;
        }
};

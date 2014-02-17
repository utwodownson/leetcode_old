/* Given a binary tree, find the maximum path sum.
 * The path may start and end at any node in the tree.
 * For example:
 * Given the below binary tree,
       1
      / \
     2   3
 * Return 6.
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
    int maxPathSum(TreeNode *root, int *maxSum) {
        if (root) {
            int leftSum = maxPathSum(root->left, maxSum);
            int rightSum = maxPathSum(root->right, maxSum);

            if (leftSum + rightSum + root->val > *maxSum) 
                *maxSum = leftSum + rightSum + root->val;

            int ret = (leftSum > rightSum ? leftSum : rightSum) + root->val;
            return ret > 0 ? ret : 0;
        }
        return 0;
    }
    public:
    int maxPathSum(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!root) return 0;
        int maxSum = root->val;
        maxPathSum(root, &maxSum);
        return maxSum;
    }
};

/* Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
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
    TreeNode *build(const int *pre, const int *in, int n) {
        if (n < 1) return 0;

        int tmp = pre[0], i;
        for (i = 0; in[i] != tmp; ++i);

        TreeNode *root = new TreeNode(tmp);
        root->left = build(pre + 1, in, i);
        root->right = build(pre + i + 1, in + i + 1, n - i - 1);

        return root;
    }
    public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder.data(), inorder.data(), inorder.size());
    }
};

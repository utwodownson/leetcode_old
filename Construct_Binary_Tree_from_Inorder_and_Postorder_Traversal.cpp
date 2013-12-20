/* Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *build(const int *in, const int *post, int n) {
        if (n < 1) return 0;

        int tmp = post[n - 1], i;
        for (i = 0; in[i] != tmp && i < n; ++i);

        TreeNode *root = new TreeNode(tmp);
        root->left = build(in, post, i);
        root->right = build(in + i + 1, post + i, n - i - 1);

        return root;
    }
    public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder.data(), postorder.data(), inorder.size());
    }
};

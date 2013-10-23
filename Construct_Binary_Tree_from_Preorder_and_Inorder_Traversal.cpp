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
        TreeNode *build(const int *preorder, const int *inorder, int size) {
            if (size < 1) 
                return 0;
            int val = preorder[0];
            TreeNode *root = new TreeNode(val);
            for (int i = 0; i < size; i++) {
                if (inorder[i] == val) {
                    root->left = build(preorder + 1, inorder, i);
                    root->right = build(preorder + 1 + i, inorder + i + 1, size - i - 1);
                    break; 
                }
            }
            return root;
        }
    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            return build(preorder.data(), inorder.data(), preorder.size());
        }
};

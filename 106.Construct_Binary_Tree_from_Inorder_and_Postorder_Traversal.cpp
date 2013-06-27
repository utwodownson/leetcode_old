/**
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
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
    TreeNode *buildTree(const int *in, const int *post, int size) {
        if (size < 1) {
            return 0;
        }
        int val = post[size - 1];
        TreeNode *root = new TreeNode(val);
        for (int i = 0; i < size; i++) {
            if (in[i] == val) {
                root->left = buildTree(in, post, i);
                root->right = buildTree(in + i + 1, post + i, size - i - 1); // woring post + i + 1
                break;
            }
        }
        return root;
    }
    public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildTree(inorder.data(), postorder.data(), postorder.size());
    }
};


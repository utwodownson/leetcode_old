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
        TreeNode *build(const int *inorder, const int *postorder, int size) {
            if (size < 1) {
                return 0;
            }
            int val = postorder[size - 1];
            TreeNode *root = new TreeNode(val);
            for (int i = 0; i < size; i++) {
                if (inorder[i] == val) {
                    root->left = build(inorder, postorder, i);
                    root->right = build(inorder + i + 1, postorder + i, size - i - 1);
                    break;
                }
            }
            return root;
        }
        public:
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            return build(inorder.data(), postorder.data(), inorder.size());
        }
    };

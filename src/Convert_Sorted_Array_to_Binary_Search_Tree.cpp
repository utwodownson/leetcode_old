/* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(const int* num, int size) {
        TreeNode *root = 0;
        if (size > 0) {
            int mid = size >> 1;
            root = new TreeNode(num[mid]);
            root->left = sortedArrayToBST(num, mid);
            root->right = sortedArrayToBST(num + mid + 1, size - mid - 1);
        }
        return root;
    }
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            return sortedArrayToBST(num.data(), num.size());
        }
};

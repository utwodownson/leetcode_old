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
        TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
            TreeNode *root = 0;
            if (start < end) {
                int mid = (start + end) / 2;
                root = new TreeNode(num[mid]);
                root->left = sortedArrayToBST(num, start, mid);
                root->right = sortedArrayToBST(num, mid + 1, end);
            }
            return root;
        }
    public:
        TreeNode *sortedArrayToBST(vector<int> &num) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            return sortedArrayToBST(num, 0, num.size());
        }
};

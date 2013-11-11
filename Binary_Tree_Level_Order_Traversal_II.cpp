/* Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
 / \
 15   7
 * return its bottom-up level order traversal as:
 [
  [15,7]
  [9,20],
  [3],
 ]
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
        void traverse(TreeNode *root, int level, vector<vector<int>> &result) {
            if (!root) return;

            if (level > result.size()) {
                vector<int> temp;
                result.push_back(temp);
            }
            result[level - 1].push_back(root->val);
            traverse(root->left, level + 1, result);
            traverse(root->right, level + 1, result);
        }
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int>> result;
            traverse(root, 1, result);
            reverse(result.begin(), result.end());
            return result;
        }
};









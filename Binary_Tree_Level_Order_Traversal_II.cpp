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
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            queue<TreeNode *> q;
            vector<vector<int> > ans;
            vector<int> level;
            if (root) {
                q.push(root);
                q.push(NULL);
            }
            while (!q.empty()) {
                root = q.front(); q.pop();
                if (root) {
                    level.push_back(root->val);
                    if (root->left) q.push(root->left);
                    if (root->right) q.push(root->right);
                } else {
                    ans.push_back(level);
                    level.clear();
                    if (!q.empty()) q.push(NULL);
                }
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

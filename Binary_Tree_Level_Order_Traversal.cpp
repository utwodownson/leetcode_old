/* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *        3
         / \
        9  20
      /  \
     15   7
 * return its level order traversal as:
   [
    [3],
    [9,20],
    [15,7]
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
        vector<vector<int> > levelOrder(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<vector<int> > ans;
            vector<int> level;
            queue<TreeNode *> q;
            TreeNode *p = root; 
            if (p) {
                q.push(p);
                q.push(NULL);
            }

            while (!q.empty()) {
                p = q.front();
                q.pop();
                if (p) {
                    level.push_back(p->val);
                    if (p->left) q.push(p->left);
                    if (p->right) q.push(p->right);
                } else {
                    ans.push_back(level);
                    level.clear();
                    if (!q.empty()) q.push(NULL);
                }
            }
            return ans;
        }
};








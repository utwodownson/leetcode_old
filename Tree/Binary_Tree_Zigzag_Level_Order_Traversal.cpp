/* Given a binary tree, 
 * return the zigzag level order traversal of its nodes' values. 
 * (ie, from left to right, then right to left for the next level and alternate between).
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
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
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            vector<vector<int> > ans;
            vector<int> level;
            queue<TreeNode *> q;
            bool flag = false; 
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
                    if (flag) reverse(level.begin(), level.end());
                    flag = !flag;
                    ans.push_back(level);
                    level.clear();
                    if (!q.empty()) q.push(NULL);
                }
            }
            return ans;
        }
};


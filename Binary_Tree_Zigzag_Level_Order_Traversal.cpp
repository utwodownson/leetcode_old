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
            vector<int> tmp;
            TreeNode *p = root;
            queue<TreeNode *> q;
            int flag = 0; // right to left 
            if (p) {
                q.push(p);
                q.push(NULL);
            }
            while (!q.empty()) {
                p = q.front();
                q.pop();
                if (p) {
                    tmp.push_back(p->val);
                    if (p->left) q.push(p->left);
                    if (p->right) q.push(p->right); 
                } else {
                    if (flag) {
                        reverse(tmp.begin(), tmp.end());
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                    ans.push_back(tmp);
                    tmp.clear();
                    if (!q.empty()) q.push(NULL);
                }
            }
            return ans;
        }
};

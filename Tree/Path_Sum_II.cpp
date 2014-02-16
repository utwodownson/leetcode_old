/* Given a binary tree and a sum, 
 * find all root-to-leaf paths where each path's sum equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
 *       5
 *      / \
 *     4   8
 *    /   / \
 *  11  13  4
 * /  \    / \
 *7    2  5   1
 *return
 * [
 *   [5,4,11,2],
 *   [5,8,4,5]
 * ]
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
    void pathSum(TreeNode *root, int gap, vector<int> &cur, vector<vector<int> > &ans) {
        if (!root) return;
        cur.push_back(root->val);
        if (!root->left && !root->right) 
            if (gap == root->val)
                ans.push_back(cur);
        pathSum(root->left, gap - root->val, cur, ans);
        pathSum(root->right, gap - root->val, cur, ans);
        cur.pop_back();
    }
    public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ans;
        vector<int> cur;
        pathSum(root, sum, cur, ans);
        return ans;
    }
};

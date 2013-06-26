/**
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 *
 * [
 *   [15,7]
 *   [9,20],
 *   [3],
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
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > ans;
            if (root == NULL) return ans;
            queue<TreeNode *> st;
            vector<int> num(0);
            st.push(root);
            int level, count = 1;
            while (!st.empty()) {
                num.clear();
                level = 0;
                for (int i = 0; i < count; ++i) {
                    root = st.front();
                    st.pop();
                    num.push_back(root->val);
                    if (root->left != NULL) {
                        st.push(root->left);
                        level++;
                    }
                    if (root->right != NULL) {
                        st.push(root->right);
                        level++;
                    }
                }
                count = level;
                ans.push_back(num);
            }
            reverse(ans.begin(), ans.end());  
            return ans;
        }
};

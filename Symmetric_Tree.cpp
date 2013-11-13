/* Given a binary tree, check whether it is a mirror of itself 
 * (ie, symmetric around its center). 
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
    bool isSymmetric(TreeNode *t1, TreeNode *t2) {
        stack<TreeNode*> st1, st2;
        while (t1 || !st1.empty()) {
            while (t1 && t2 && t1->val == t2->val) {
                st1.push(t1);
                st2.push(t2);
                t1 = t1->left;
                t2 = t2->right;
            }
            if (t1 != t2) return false;

            t1 = st1.top()->right;
            t2 = st2.top()->left;
            st1.pop();
            st2.pop();
        }

        return t1 == t2;
    }
    public:
    bool isSymmetric(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return !root || isSymmetric(root->left, root->right);
    }
};

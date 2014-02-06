/* Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
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
        void recoverTree(TreeNode *root) {
            stack<TreeNode *> st;
            TreeNode *p = root;
            TreeNode *last = 0, *first = 0, *second = 0;
            while (p || !st.empty()) {
                if (p) {
                    st.push(p);
                    p = p->left;
                } else {
                    p = st.top(); st.pop();
                    if (last && last->val > p->val) {
                        if (first) {
                            swap(first->val, p->val);
                            return;
                        }
                        first = last;
                        second = p;
                    }
                    last = p;
                    p = p->right;
                }
            }
            if (first && second) swap(first->val, second->val);
        }
};

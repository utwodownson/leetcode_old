/* Given a binary tree
 *  struct TreeLinkNode {
 *      TreeLinkNode *left;
 *      TreeLinkNode *right;
 *      TreeLinkNode *next;
 *  }
 *  Populate each next pointer to point to its next right node. 
 *  If there is no next right node, the next pointer should be set to NULL.
 *  Initially, all next pointers are set to NULL.
 *  Note:
 *       You may only use constant extra space.
 *       You may assume that it is a perfect binary tree 
 *       (ie, all leaves are at the same level, and every parent has two children).
 *  For example,
 *  Given the following perfect binary tree,
 *        1
 *       / \
 *      2   3
 *     / \  / \
 *    4  5  6  7
 *  After calling your function, the tree should look like:
 *        1 -> NULL
 *      /  \
 *     2 -> 3-> NULL
 *    / \  / \
 *   4->5->6->7 -> NULL
 */
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    void connect(TreeLinkNode *root, TreeLinkNode *sub) {
        if (!root) return; 
        else root->next = sub;
        connect(root->left, root->right);
        if (sub) connect(root->right, sub->left);
        else connect(root->right, NULL);
    }
    public:
    void connect(TreeLinkNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        connect(root, NULL);
    }
};

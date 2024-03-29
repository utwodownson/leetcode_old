/* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *left = new ListNode(0), *p = left;
            ListNode *right = new ListNode(0), *q = right;
            while (head) {
                if (head->val < x) {
                    p->next = head;
                    p = head;
                } else {
                    q->next = head;
                    q = head;
                }
                head = head->next;
            }
            p->next = right->next;
            q->next = NULL;
            return left->next;
        }
};

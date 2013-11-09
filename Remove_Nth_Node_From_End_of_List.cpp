/* Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *p = head, *q = head, *pre = 0; 
            for (int i = 0; i < n; ++i) {
                if (q == NULL)
                    return head;
                q = q->next;
            }

            while (q) {
                pre = p;
                p = p->next;
                q = q->next;
            }

            if (pre)
                pre->next = p->next;
            else
                head = p->next;
            delete p;
            return head;
        }
};

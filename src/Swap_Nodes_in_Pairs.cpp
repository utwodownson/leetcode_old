/* Given a linked list, swap every two adjacent nodes and return its head.
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * Your algorithm should use only constant space. 
 * You may not modify the values in the list, only nodes itself can be changed.
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
        ListNode *swapPairs(ListNode *head) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *p = head, *q = 0, *pre = 0;
            while (p) {
                q = p->next;
                if (q) {
                    p->next = q->next;
                    q->next = p;
                    if (!pre) head = q;
                    else pre->next = q;
                } else {
                    return head;
                }
                pre = p;
                p = p->next;
            }
            return head;
        }
};

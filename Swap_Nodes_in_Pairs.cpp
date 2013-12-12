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
            ListNode *begin = new ListNode(0), *r, *p, *q;
            begin->next = head;
            for (r = p = q = begin; p && q; r = p) {
                if (r->next && r->next->next) {
                    p = r->next;
                    q = r->next->next;
                    p->next = q->next;
                    q->next = p;
                    r->next = q;
                } else break;
            }
            return begin->next;
        }
};

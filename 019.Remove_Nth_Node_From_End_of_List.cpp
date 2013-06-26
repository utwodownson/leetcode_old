/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
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
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode *pre = 0, *p = head, *q = head;
            for (int i = 0; i < n; ++i) {
                if (!p) return head;
                p = p->next;
            }
            while (p) {
                pre = q;
                p = p->next;
                q = q->next;
            }
            /* wrong
            pre->next = q->next;
            delete q;
            return head;
            */
            if (q) {
                if (pre) {
                    pre->next = q->next;
                } else {
                    head = q->next;
                }
                delete q;
            }
            return head;
        }
};

/* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * Follow up:
 * Can you solve it without using extra space?
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
        ListNode *detectCycle(ListNode *head) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            ListNode *p = head, *q = head;
            while (q && q->next) {
                p = p->next;
                q = q->next->next;
                if (p == q) break;
            }
            if (!q || !q->next) return NULL;

            p = head;
            while (p != q) {
                p = p->next;
                q = q->next;
            }
            return p;
        }
};

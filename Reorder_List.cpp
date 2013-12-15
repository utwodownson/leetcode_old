/* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You must do this in-place without altering the nodes' values.
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
        void reorderList(ListNode *head) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if (!head) return;
            ListNode *p = 0, *q = 0, tmp = 0;
            for (p = head, q = head; q && q->next; p = p->next, q = q->next->next);
            q = p->next;
            p->next = 0;
            for (p = q; p; tmp = p, p = q) {
                q = p->next;
                p->next = tmp;
            }
            for (p = tmp, q = head; p; q = q->next->next, p = tmp) {
                tmp = p->next;
                p->next = q->next;
                q->next = p;
            }
        }
};

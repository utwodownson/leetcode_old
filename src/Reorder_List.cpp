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
        ListNode *reverse(ListNode *head) {
            if (!head) return head;
            ListNode *p = head, *q = head->next, *r = NULL;
            p->next = NULL;
            while (q) {
                r = q->next;
                q->next = p;
                p = q;
                q = r; 
            }
            return p;
        }
    public:
        void reorderList(ListNode *head) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if (!head) return;
            ListNode *p = head, *q = head;
            while (q && q->next) {
                p = p->next;
                q = q->next->next;
            }

            q = p->next;
            p->next = NULL;
            p = q;

            p = reverse(p);
            q = head;
            while (p) {
                ListNode *r = p->next;
                p->next = q->next;
                q->next = p;
                q = q->next->next;
                p = r;
            }
        }
};

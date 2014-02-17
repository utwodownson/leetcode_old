/* Sort a linked list using insertion sort. */
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
        ListNode *insertionSortList(ListNode *head) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if (!head || !head->next) return head;
            ListNode *p = head->next, *q = head, *r = NULL, *pre = head;
            while (p) {
                q = head;
                if (head->val > p->val) {
                    pre->next = p->next;
                    p->next = q;
                    head = p;
                } else {
                    while (q != p && q->val <= p->val) {
                        r = q;
                        q = q->next;
                    }
                    if (p == q) 
                        pre = p;
                    else {
                        pre->next = p->next;
                        p->next = q;
                        r->next = p;
                    }
                }
                p = pre->next;
            }
            return head;
        }
};

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
            if (!head || !head->next) return NULL;
            ListNode *access = 0;
            for (ListNode *p = head->next, *q = head->next->next; q && q->next; p = p->next, q = q->next->next) {
                if (p == q) {
                    ListNode *tmp = 0, *begin = 0;
                    for (tmp = p, begin = head; tmp != begin; tmp = tmp->next, begin = begin->next);
                    return tmp;
                } 
            }
            return NULL;
        }
};

/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/

class Solution {
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *p = 0, *head = new ListNode(-1);
        for (p = head; l1 && l2; p = p->next) { 
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return head->next;
    }
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!lists.size()) return NULL;

        ListNode *p = lists[0];
        for (int i = 1; i < lists.size(); ++i) 
            p = mergeTwoLists(p, lists[i]);
        return p;
    }
};

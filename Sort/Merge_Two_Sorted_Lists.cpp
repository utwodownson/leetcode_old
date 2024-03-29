/* Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
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
};

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
            ListNode *head = 0, *p;
            while (l1 && l2) {
                if (l1->val < l2->val) {
                    if (head == 0) {
                        head = p = l1;
                        l1 = l1->next;
                    } else {
                        p->next = l1;
                        p = l1;
                        l1 = l1->next;
                    }
                } else {
                    if (head == 0) {
                        head = p = l2;
                        l2 = l2->next;
                    } else {
                        p->next = l2;
                        p = l2;
                        l2 = l2->next;
                    }
                }
            }
            if (l1) 
                p->next = l1;
            if (l2) 
                p->next = l2;
            return head;
        }
};

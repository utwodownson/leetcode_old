/* Given a sorted linked list, delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
        ListNode *deleteDuplicates(ListNode *head) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (!head) return head;
            ListNode *p = head;
            for (ListNode *q = head->next; q; q = q->next) {
                if (p->val != q->val) {
                    p->next = q;
                    p = q;
                }
            }
            p->next = 0;
            return head;
        }
};

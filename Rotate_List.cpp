/* Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
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
        ListNode *rotateRight(ListNode *head, int k) {
            ListNode *tmp = head, *p = NULL;
            int len = 1;
            for (p = head; p && p->next; p = p->next) ++len;
            for (int i = 1; i < len - k % len; ++i) tmp = tmp->next;
            if (p) {
                p->next = head;
                head = tmp->next;
                tmp->next = 0;
            }
            return head;
        }
};

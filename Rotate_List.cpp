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
            int len = 1;
            ListNode *tail = NULL;
            for (tail = head; tail && tail->next; tail = tail->next) len++;
            if (tail) {
                tail->next = head;
                k = len - k % len;
                while (k-- > 0) 
                    tail = tail->next;
                head = tail->next;
                tail->next = 0;
            }
            return head;
        }
};

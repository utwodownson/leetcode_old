/* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
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
        ListNode *reverseKGroup(ListNode *head, int k) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *begin = new ListNode(0), *first = begin, *p = begin, *q, *last;
            begin->next = head;
            for ( ; last; first->next = last) {
                first = last = p;
                p = first->next;
                for (int i = 0; i < k; ++i) {
                    if (!last) break;
                    last = last->next;
                }
                if (!last) return begin->next;
                for (ListNode *tmp = last->next; tmp != last; tmp = p, p = q) {
                    q = p->next;
                    p->next = tmp;
                }
                p = first->next;
            }
            return begin->next;
        }
};


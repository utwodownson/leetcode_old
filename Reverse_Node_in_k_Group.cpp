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
            ListNode *p = head, *pre = 0, *q = head;
            int len = 0;
            while (p) {
                p = p->next;
                len++;
            }
            for (int i = 0; i < len / k; ++i) {
                p = 0;
                for (int j = 0; j < k; ++j) {
                    ListNode *r = q->next;
                    q->next = p;
                    p = q;
                    q = r;
                }
                if (pre) {
                    pre->next->next = q;
                    ListNode *r = pre->next;
                    pre->next = p;
                    pre = r;
                } else {
                    pre = head;
                    head->next = q;
                    head = p;
                }
            }
            return head;
        }
};


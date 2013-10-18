/* Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
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
        ListNode *partition(ListNode *head, int x) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *less = 0, *greater = 0, *p, *q;
            while (head) {
                if (head->val < x) {
                    if (less == 0) {
                        less = p = head;
                    } else {
                        p->next = head;
                        p = p->next;
                    }
                } else {
                    if (greater == 0) {
                        greater = q = head;
                    } else {
                        q->next = head;
                        q = q->next;
                    }
                }
                head = head->next;
            }

            if (greater) 
                q->next = 0;
            if (less) 
                p->next = greater;
            else
                less = greater;
            return less;
        }
};

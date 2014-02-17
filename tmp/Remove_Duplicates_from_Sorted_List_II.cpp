/* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
            if (!head || !head->next) return head;

            ListNode *begin = new ListNode(0), *p = begin, *q = head;
            int tmp = q->val - 1;

            while (q->next) {
                if (q->val != tmp) {
                    if (q->val != q->next->val) {
                        tmp = q->val;
                        p->next = q;
                        p = p->next;
                    } else 
                        tmp = q->val;
                }
                q = q->next;
            }
            if (q->val != tmp) { 
                p->next = q;
                p = p->next;
            }
            p->next = NULL;
            return begin->next;
        }
};

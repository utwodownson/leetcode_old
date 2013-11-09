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
            ListNode *p = 0, *q = head;
            head = 0;
            bool flag = true; // the last duplicate q
            while (q) {
                ListNode *r = q->next;
                if (r == 0 || q->val != r->val) {
                    if (flag) {
                        if (p == 0) {
                            head = q;
                        } else {
                            p->next = q;
                        }
                        p = q;
                    } else {
                        delete q;
                    }
                    flag = true;
                } else {
                    delete q;
                    flag = false;
                }
                q = r;
            }
            if (p) 
                p->next = NULL;
            return head;
        }
};

/* Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * return 1->4->3->2->5->NULL.
 * Note:
 * Given m, n satisfy the following condition:
 * 1 ≤ m ≤ n ≤ length of list.
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
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *tmp = new ListNode(0); tmp->next = head;
            ListNode *begin = tmp, *p = NULL, *r = NULL, *q = NULL;

            for (int i = 1; i < m; ++i) 
                begin = begin->next;

            p = begin->next;
            while (m <= n) {
                q = p->next;
                p->next = r;
                r = p;
                p = q;
                m++;
            }
            begin->next->next = p;
            begin->next = r;
            return tmp->next;
        }
};


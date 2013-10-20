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
            ListNode *pre = 0, *first = head, *tmp = 0, *last;
            for (int i = 1; i < m; ++i) {
                pre = first;
                first = first->next;
            }
            while (m <= n) {
                last = first->next;
                first->next = tmp;
                tmp = first;
                first = last;
                m++;
            }

            if (pre) {
                pre->next->next = first;
                pre->next = tmp;
            } else {
                head->next = first;
                head = tmp;
            }
            return head;
        }
};


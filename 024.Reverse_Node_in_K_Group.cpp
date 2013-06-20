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
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode *p = head, *q = NULL, *last = NULL;
            for (int i = 0; i < k - 1; ++i) head = head->next;
            last = head->next;
            for (int i = 0; i < k - 1; ++i) {
                q = p->next;
                p->next = last;
                last = p;
                p = q;
            }
            head->next = last;
            return head;
        }
};

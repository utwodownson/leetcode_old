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
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode *tail = head, *pre = 0, *cur = head;
            for (int i = 0; i < n; i++) {
                if (0 == tail) {
                    return head;
                }
                tail = tail->next;
            }
            while (tail) {
                pre = cur;
                cur = cur->next;
                tail = tail->next;
            }
            if (cur) {
                if (pre) {
                    pre->next = cur->next;
                } else {
                    head = cur->next;
                }
                delete cur;
            }
            return head;
        }
};

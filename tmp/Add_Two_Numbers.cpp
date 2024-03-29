/*
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            ListNode *head = new ListNode(0);
            ListNode *p = head;
            int tmp = 0;
            while (l1 || l2) {
                if (l1) { tmp += l1->val; l1 = l1->next; }
                if (l2) { tmp += l2->val; l2 = l2->next; }
                p->next = new ListNode(tmp % 10); p = p->next;
                tmp = tmp / 10;
            }
            if (tmp) p->next = new ListNode(tmp);
            return head->next;
        }
};

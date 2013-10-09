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
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int c = 0;
            ListNode *p = 0, *sum = 0; // sum is the head
            while (l1 || l2 || c > 0) { // l1 || l2 || c > 0
                int tmp = c;
                if (l1) {
                    tmp += l1->val;
                    l1 = l1->next;
                }
                if (l2) {
                    tmp += l2->val;
                    l2 = l2->next;
                }
                ListNode *q = new ListNode(tmp % 10);
                if (p) {
                    p->next = q;
                    p = q;
                } else {
                    sum = p = q;
                }
                c = tmp / 10; 
            }
            return sum;
        }
};
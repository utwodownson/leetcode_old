/* A linked list is given such that each node contains an additional random pointer 
 * which could point to any node in the list or null.
 * Return a deep copy of the list.
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (!head) return head;
            for (RandomListNode *h = head; h != NULL; h = h->next->next) {
                RandomListNode *p = new RandomListNode(h->label);
                p->next = h->next;
                h->next = p;
            }

            for (RandomListNode *h = head; h != NULL; h = h->next->next) 
                h->random == NULL ? h->next->random = NULL : h->next->random = h->random->next;

            RandomListNode *copyhead = head->next;
            for (RandomListNode *h1 = head, *h2 = copyhead; ; h1 = h1->next, h2 = h2->next) {
                h1->next = h1->next->next;
                if (!h1->next) break;
                h2->next = h2->next->next;
            }
            return copyhead;
        }
};

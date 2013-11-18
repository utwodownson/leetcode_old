/* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.*/

class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            ListNode *sorted = 0;
            vector<ListNode*> heap(lists.size() + 1, 0);
            int size = 0;

            for (int i = 0; i < lists.size(); ++i) {
                ListNode *key = lists[i];
                if (key == 0) continue;

                int j = size++, k = (j - 1) / 2;
                while (j > 0 && heap[k]->val > key->val) {
                    heap[j] = heap[k];
                    j = k;
                    k = (j - 1) / 2;
                }
                heap[j] = key;
            }

            ListNode *key = 0, *p = 0;
            if (size > 0) key = heap[0];
            while (size > 0) {
                int i = 0, j = 0;
                do {
                    heap[i] = heap[j];
                    i = j;
                    j = 2 * i + 1;
                    if (j + 1 < size && heap[j]->val > heap[j + 1]->val) j++;
                } while (j < size && key->val > heap[j]->val);

                heap[i] = key;

                if (sorted) {
                    p->next = new ListNode(heap[0]->val);
                    p = p->next;
                } else {
                    sorted = p = new ListNode(heap[0]->val);
                }

                key = heap[0]->next;
                if (key == 0) {
                    key = heap[--size];
                }
            }
            return sorted;
        }
};

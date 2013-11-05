#include <stdio.h>
#include <stdlib.h>

#define N 1010

int n, m;
int a[N];

typedef struct Node {
    int val;
    Node *next;
    Node *pre;
}ListNode;

void print_list(ListNode *head) {
    ListNode *p = head;
    while (p->pre != head) {
        printf("%d ", p->val);
        p = p->pre;
    }
    printf("%d\n", p->val);
}

ListNode *haveseat() {
    ListNode *tmp = (ListNode *) malloc(sizeof(ListNode));
    tmp->val = a[0];
    tmp->next = tmp;
    tmp->pre = tmp;
    ListNode *p = tmp;
    int len = 1;

    for (int i = 1; i < n; ++i) {
        int k = (m - 1) % len;
        while (k-- > 0) 
            p = p->next;
        ListNode *pre = p, *last = p->next;
        ListNode *tmp = (ListNode *) malloc(sizeof(ListNode));
        tmp->val = a[i];
        tmp->next = last;
        tmp->pre = pre;
        last->pre = tmp;
        pre->next = tmp;
        p = tmp;
        len++;
    }
    return p;
}

int main() 
{
    int id;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) 
            scanf("%d", &a[i]);
        ListNode *head = haveseat();
        print_list(head);
    }
}

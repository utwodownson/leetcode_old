#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define N 1010

int n, m;
int a[N];

typedef struct Node {
    int val;
    Node *next;
    Node *pre;
    Node(int x, Node *left, Node *right) : val(x), pre(left), next(right) {}
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
    ListNode *head, *tail, *p;
    ListNode *tmp = new ListNode(a[0], tmp, tmp);
    head = tail = p = tmp;
    for (int i = 1; i < n; ++i) {
        ListNode *tmp = new ListNode(a[i], p, head);
        p->next = tmp;
        tail = p = tmp;
        head->pre = tail;
    }
    return tail;
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

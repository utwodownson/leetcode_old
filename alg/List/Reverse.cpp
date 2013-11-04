#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int val;
    _Node *next;
}Node;

void print(Node *head) {
    Node *p = head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

Node* reserve(Node *head) {
    if (!head) return head;
    Node *p = head, *q = head->next, *r = NULL;
    p->next = NULL;
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}

void reorderList(Node *head) {
    Node *p = head, *q = head;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
    }

    q = p->next;
    p->next = NULL;
    p = q;

    p = reserve(p);
    q = head;
    while (p) {
        Node *r = p->next;
        p->next = q->next;
        q->next = p;
        q = q->next->next;
        p = r;
    }
}

int main() 
{
    int n;
    while (scanf("%d", &n) != EOF) {
        Node *head = NULL;
        Node *a = (Node *) malloc(sizeof(Node));
        scanf("%d", &a->val);
        a->next = NULL;
        head = a;
        for (int i = 1; i < n; ++i) {
            Node *tmp = (Node *) malloc(sizeof(Node));
            scanf("%d", &tmp->val);
            head->next = tmp;
            tmp->next = NULL; 
            head = tmp;
        }
        head = a;
        print(head);
        printf("Input\n");
        //head = reserve(head);
        reorderList(head);
        print(head);
    }
}

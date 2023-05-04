#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

ListNode* x(ListNode* l1, ListNode* l2) {
    ListNode y = {0}, *current = &y;

    while (l1 && l2) {
        if (l1->data < l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    current->next = l1 ? l1 : l2;

    return y.next;
}

int main() {
    ListNode l1[] = {{1, &l1[1]}, {2, &l1[2]}, {4, NULL}};
    ListNode l2[] = {{1, &l2[1]}, {3, &l2[2]}, {4, NULL}};

    ListNode* y = x(l1, l2);

    while (y) {
        printf("%d ", y->data);
        y = y->next;
    }

    return 0;
}

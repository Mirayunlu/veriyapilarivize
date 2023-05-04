#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* x(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* addLists(struct Node* l1, struct Node* l2) {
    struct Node* z = NULL;
    struct Node *temp, *prev = NULL;
    int y = 0, sum;

    while (l1 != NULL || l2 != NULL) {
        sum = y + (l1 ? l1->data : 0) + (l2 ? l2->data : 0);

        y = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        temp = x(sum);

        if (z == NULL) {
            z = temp;
        }
        else {
            prev->next = temp;
        }

        prev = temp;

        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }

    if (y > 0) {
        temp->next = x(y);
    }

    return z;
}

int main() {
    struct Node* l1 = x(9);
    l1->next = x(2);
    l1->next->next = x(3);

    struct Node* l2 = x(8);
    l2->next = x(1);
    l2->next->next = x(5);

    struct Node* z = addLists(l1, l2);

    printf("Toplam: ");

    while (z!= NULL) {
        printf("%d ", z->data);
        z = z->next;
    }

    return 0;
}

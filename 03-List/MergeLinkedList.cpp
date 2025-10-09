//
// Created by sinil on 2025-09-30.
//
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;


ListNode *createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode *head = (ListNode *) malloc(sizeof(ListNode));
    head->data = arr[0];
    head->link = NULL;

    ListNode *current = head;
    for (int i = 1; i < size; i++) {
        ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
        new_node->data = arr[i];
        new_node->link = NULL;
        current->link = new_node;
        current = new_node;
    }
    return head;
}

void printList(ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

void display(ListNode * phead) {
    ListNode *p = phead;
    while (p != NULL) {
        printf("| %d | %x | ---> \n",p->data,p->link);
        p = p->link;
    }

}

ListNode *merge(ListNode *head1, ListNode *head2) {
    ListNode dummy;
    ListNode *p = &dummy;
    dummy.link = NULL;

    if (head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        while (head1 != NULL && head2 != NULL) {
            if (head1->data <= head2->data) {
                p->link = head1;
                head1 = head1->link;
            } else {
                p->link = head2;
                head2 = head2->link;
            }
            p = p->link;
        }

        if (head1 != NULL) p->link = head1;
        if (head2 != NULL) p->link = head2;
        return dummy.link;
    }
}

int main() {
    int a1[] = {1, 2, 5, 10, 15, 20, 25};
    int b1[] = {3, 7, 8, 15, 18, 30};
    ListNode *a = createList(a1, 7);
    ListNode *b = createList(b1, 6);

    ListNode * c = merge(a,b);
    display(c);
    return 0;
}

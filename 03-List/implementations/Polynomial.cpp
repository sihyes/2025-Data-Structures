#include <stdio.h>
#include <stdlib.h>
//
// Created by sinil on 2025-10-08.
//
typedef struct ListNode {
    int coef;
    int expon;
    struct ListNode *link;
}ListNode;

ListNode *A, *B;

typedef struct ListHeader {
    int length;
    ListNode *head;
    ListNode *tail;
}ListHeader;

void error(const char * message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ListHeader *plist) {
    plist->length = 0;
    plist->head=plist->tail=NULL;
}
void insert_node_last(ListHeader *plist, int coef, int expon) {
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL) error("Memory allocation error");

    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;

    if (plist->tail == NULL) {
        plist->head=plist->tail=temp;
    }
    else {
        plist->tail->link = temp;
        plist->tail = temp;
    }
    plist->length++;
}
//list3 = list1+list2
void poly_add(ListHeader *plist1, ListHeader *plist2, ListHeader *plist3) {
    ListNode *a = plist1->head;
    ListNode *b = plist2->head;
    int sum;
    while (a && b) { // 둘중 하나가 null이면 끝남! 아래 for문에서 나머지 처리. (계수비교 필요없는애들)
        if (a->expon == b->expon) {
            sum = a->coef + b->coef;
            if (sum != 0) insert_node_last(plist3,sum,a->expon);
            a=a->link;
            b=b->link;
        }
        else if (a->expon > b->expon) {
            insert_node_last(plist3,a->coef,a->expon);
            a=a->link;
        }
        else { // a의 차수보다 b의 차수가 더 큰경우
            insert_node_last(plist3,b->coef,b->expon);
            b=b->link;
        }
    }
    for (;a!=NULL;a=a->link)
        insert_node_last(plist3,a->coef,a->expon);
    for (;b!=NULL;b=b->link)
        insert_node_last(plist3,b->coef,b->expon);
}

void poly_print(ListHeader *plist) {
    ListNode *p = plist->head;
    for (;p;p=p->link) {
        printf("%d %d\n", p->coef,p->expon);
    }
}

int main() {
    ListHeader list1, list2, list3;
    // Initialization of linked list
    init(&list1);
    init(&list2);
    init(&list3);
    // Generate polynomial 1
    insert_node_last(&list1, 3, 12);
    insert_node_last(&list1, 2, 8);
    insert_node_last(&list1, 1, 0);
    // Generate polynomial 2
    insert_node_last(&list2, 8, 12);
    insert_node_last(&list2, -3, 10);
    insert_node_last(&list2, 10, 6);
    // Poly 3 = Ploy 1 + Poly 2
    poly_add(&list1, &list2, &list3);
    poly_print(&list3);

    return 0;
}

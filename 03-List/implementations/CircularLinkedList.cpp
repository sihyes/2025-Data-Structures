#include <cstddef>
//
// Created by sinil on 2025-10-08.
//
typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void insert_first(ListNode **phead, ListNode* node) {
    if (*phead == NULL) {
        *phead = node;
        node->link = node; //단일노드리스트
    }
    else {
        node->link = (*phead)->link;
        (*phead)->link = node;

    }
}

//시간복잡도 : O(1)
void insert_last(ListNode **phead, ListNode* node) {
    if (*phead == NULL) {
        *phead = node;
        node->link = node; //단일노드리스트
    }
    else {
        node->link = (*phead)->link;
        (*phead)->link = node;
        *phead = node;
    }
}
#include <stdlib.h>
//
// Created by sinil on 2025-10-08.
//
typedef int element;
typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
}DlistNode;

void init(DlistNode *phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void dinsert_node(DlistNode* before, DlistNode *new_node) {

    new_node->llink=before;
    new_node->rlink=before->rlink;//1 새로운노드에 기존거 주소 옮겨주기
    (before->rlink)->llink = new_node;
    before->rlink = new_node;
}

void dremove_node(DlistNode* phead_node, DlistNode *removed) {
    if( removed == phead_node ) return;
    (removed->llink)->rlink = removed->rlink;
    (removed->rlink)->llink = removed->llink;
    free(removed);
}
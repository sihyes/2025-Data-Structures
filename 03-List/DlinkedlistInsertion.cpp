//
// Created by sinil on 2025-09-29.
//
#include <iostream>
using namespace std;
typedef int element;
typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

void init(DlistNode *phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void display(DlistNode *phead) {
    DlistNode *p;
    for (p = phead->rlink; p!= phead; p= p->rlink) {
        printf("<--- | %x | %d | %x | ---> \n",p->llink,p->data,p->rlink);
    }
    printf("\n");
}

//Insert 'new_node' into the right of 'before'
void dinsert_node(DlistNode *before, DlistNode *new_node) {
    new_node -> llink = before;
    new_node->rlink = before->rlink;
    before->rlink->llink = new_node;
    before->rlink = new_node;

}

void dremove_node(DlistNode *phead_node,DlistNode *removed) {
    if (removed == phead_node) return;
    removed -> llink ->rlink = removed -> rlink;
    removed ->rlink->llink = removed -> llink;
    free(removed);
};

void dinsert_first_node(DlistNode *head, DlistNode *new_node) {
    dinsert_node(head, new_node);
}
void dinsert_last_node(DlistNode *head, DlistNode *new_node) {
    dinsert_node(head->llink, new_node);
}

int main() {
    DlistNode head_node;
    DlistNode *p[7];

    init(&head_node);
    for (int i=0; i<5; i++) {
        p[i] = (DlistNode *)malloc(sizeof(DlistNode));
        p[i] -> data = i;
        if (i==0){dinsert_node(&head_node, p[i]);}
        else dinsert_node(p[i-1],p[i]);
    }
    // dremove_node(&head_node,p[4]);
    display(&head_node);

    p[5] = (DlistNode *)malloc(sizeof(DlistNode));
    p[5] -> data = 5;
    dinsert_last_node(&head_node,p[5]); // headnode의 llink가 마지막노드! 마지막노드에 삽입해줘용
    display(&head_node);

    p[6] = (DlistNode *)malloc(sizeof(DlistNode));
    p[6] -> data = 6;
    dinsert_first_node(&head_node,p[6]); //제일 앞에 넣어줍니다.
    display(&head_node);
return 0;
}
#include <cstdio>
#include <process.h>
#include <stdlib.h>
//
// Created by sinil on 2025-10-08.
//
//defination
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;
// !!! Insertion !!!
// 여기에서 phead는 list의 head pointer를 가리키는 pointer이다.
// pointer -> head pointer(address of first node), 즉 address of address (주소를 가리키는 주소!)
void insert_node(ListNode **phead, ListNode *before_node, ListNode *new_node) {
    if (*phead == NULL) {
        // case1
        new_node->link = NULL;
        *phead = new_node;
    } else {
        //case2
        if (before_node == NULL) { error("The precefing node cannot be NULL"); } else {
            new_node->link = NULL;
            before_node->link = new_node;
        }
    }
}

void insert_first(ListNode **phead, ListNode *new_node) {
    if (*phead == NULL) {
        // if the list is blank
        new_node->link = NULL;
        *phead = new_node;
    } else {
        new_node->link = *phead;
        *phead = new_node;
    }
}

void insert_last(ListNode **phead, ListNode *new_node) {
    if (*phead == NULL) {
        // if the list is blank
        new_node->link = NULL;
        *phead = new_node;
    } else {
        new_node->link = NULL;
        ListNode *last = *phead;
        while (last->link != NULL) // 리스트의 마지막 노드의 주소를 last에 담는다. 결과 last->link == NULL인 상태.
            last = last->link;
        last->link = new_node;
    }
}

void insertion(ListNode **phead, ListNode *before_node, ListNode *new_node) {
    if (*phead == NULL) {// case1 if the list is blank
        new_node->link = NULL;
        *phead = new_node;
    }else if (before_node == NULL) { // case2 first에 넣기
        new_node->link = *phead;
        *phead = new_node;
    } else {//case3&4, middle에 or end case4 end에 삽입
        new_node->link = before_node->link; // NULL이어도 그대로 받아가면 된다. NULL이면 그냥 넣을 수 있나?
        before_node->link = new_node;
    }
}


// !!! Deletion !!!
void remove_node(ListNode **phead, ListNode* before_node, ListNode* removed) {
    if (*phead == NULL) error("The list is blank");
    else {
        if (before_node == NULL) { error("The precefing node cannot be NULL");}
        else {
            before_node->link = removed->link;
            free(removed);
        }
    }
}

void remove_first(ListNode **phead, ListNode* removed) {
    if (*phead == NULL) error("The list is blank");
    else {
        *phead = (*phead)->link; // *phead = removed였으니까 그 다음거로 옮겨준다.
        free(removed);
    }
}

void deletion(ListNode **phead, ListNode *before_node, ListNode* removed) {
        if (*phead == NULL) error("The list is blank");
        else {
            if (before_node == NULL) {
                *phead = (*phead)->link; // *phead = removed였으니까 그 다음거로 옮겨준다.
            }else {
                before_node->link = removed->link;
            }
            free(removed);
        }
}

void insertion_deletion(int flag, ListNode **phead, ListNode *before_node, ListNode* node) {
    if (flag == 0)
        {
        if (*phead == NULL) {// case1 if the list is blank
            node->link = NULL;
            *phead = node;
        }else if (before_node == NULL) { // case2 first에 넣기
            node->link = *phead;
            *phead = node;
        } else {//case3&4, middle에 or end case4 end에 삽입
            node->link = before_node->link; // NULL이어도 그대로 받아가면 된다.
            before_node->link = node;
        }
    }
    else if (flag == 1)
        {
        if (*phead == NULL) error("The list is blank");
        else {
            if (before_node == NULL) {
                *phead = (*phead)->link; // *phead = removed였으니까 그 다음거로 옮겨준다.
            }else {
                before_node->link = node->link;
            }
            free(node);
        }
    }
    else
        error("invalid range value. must be 0 or 1 [ insertion : 0 |  deletion : 1 ]");
}

void display_by_Iteration(ListNode* head) {
    ListNode *p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->link;
    }
    printf("\n");
}

void display_by_Recursion(ListNode* head) {
    ListNode *p = head;
    if (p != NULL) {
        printf("%d->",p->data);
        display_by_Recursion(p->link);
    }
}

ListNode* search(ListNode* head, int x) {
    ListNode* p;
    p= head;
    while (p != NULL) {
        if (p->data == x) return p;
        p = p->link;
    }
    return p; // return null 못찾았을때
}

//merge
ListNode* concat(ListNode* head1, ListNode* head2) {
    ListNode * p;
    if (head1 == NULL)return head2;
    else if (head2 == NULL) return head1;
    else {
        p = head1;
        while (p->link != NULL)
            p = p->link;
        p->link = head2;
        return head1;
    }
}

//reverse operation
ListNode* reverse(ListNode* head) {
    ListNode *p, *q, *r;
    p = head;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q; // q = head pointer of the rever ordered list
}
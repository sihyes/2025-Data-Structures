#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//
// Created by sinil on 2025-09-30.
//
#define TRUE 1
#define FALSE 0
typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

typedef struct {
    ListNode *head; // head pointer
    ListNode *tail; // tail pointer
    int length; // of nodes
} ListType;

int is_empty(ListType *list) {
    if (list->head == NULL) return 1;
    else return 0;
}

int get_length(ListType *list) {
    return list->length;
}

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
};

ListNode *get_node_at(ListType *list, int pos) {
    int i = 0;
    ListNode *tmp_node = list->head;
    if (pos < 0) return NULL;
    for (i = 0; i < pos; i++)
        tmp_node = tmp_node->link;
    return tmp_node;
}

void insert_node(ListNode **phead, ListNode *preceding_node, ListNode *new_node) {
    if (*phead == NULL) {
        new_node->link = NULL;
        *phead = new_node;
    } else {
        if (preceding_node == NULL) {
            error("The preceding node cannot be NULL. \n");
        } else {
            new_node->link = preceding_node->link;
            preceding_node->link = new_node;
        }
    }
}

void insert_first(ListNode **phead, ListNode *new_node) {
    if (*phead == NULL) {
        new_node->link = NULL;
        *phead = new_node;
    } else {
        new_node->link = *phead;
        *phead = new_node;
    }
}


void add(ListType *list, int position, element data) {
    ListNode *p;
    if ((position >= 0) && (position <= list->length)) {
        ListNode *node = (ListNode *) malloc(sizeof(ListNode));
        if (node == NULL) error("Memmory allocation error");
        node->data = data;
        if (position == 0) {
            insert_first(&(list->head), node);
        } else {
            p = get_node_at(list, position - 1);
            insert_node(&(list->head), p, node);
        }
        if (position == list->length) list->tail = node;
        list->length++;
    }
}

void remove_first(ListNode **phead, ListNode *removed) {
    if (*phead == NULL) {
        error("The List is blank \n");
    } else {
        *phead = (*phead)->link;
        free(removed);
    }
}

void remove_node(ListNode **phead, ListNode *preceding_node, ListNode *removed) {
    if (*phead == NULL) {
        error("The List is blank \n");
    } else {
        if (preceding_node == NULL) printf("The preceding node cannot be null \n");
        else {
            preceding_node->link = removed->link;
            free(removed);
        }
    }
}

void delete_(ListType *list, int pos) {
    if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
        if (pos == 0) {
            ListNode *removed = get_node_at(list, pos);
            remove_first(&(list->head), removed);
        } else {
            ListNode *p = get_node_at(list, pos - 1);
            ListNode *removed = get_node_at(list, pos);
            remove_node(&(list->head), p, removed);
            if (pos == list->length - 1) {
                list->tail = p; // 마지막 노드 삭제 후 tail을 이전 노드로 갱신
            }
        }
        list->length--;
    }
}

element get_entry(ListType *list, int pos) {
    ListNode *p;
    if (pos >= list->length) error("Position error");
    p = get_node_at(list, pos);
    return p->data;
}

void display(ListType *list) {
    int i;
    ListNode *node = list->head;
    printf("(");
    for (i = 0; i < list->length; i++) {
        printf("%d ", node->data);
        node = node->link;
    }
    printf(")\n");
}

int is_in_list(ListType *list, element item) {
    ListNode *p;
    p = list->head;
    while ((p != NULL)) {
        if (p->data == item)
            break;
        p = p->link;
    }
    if (p == NULL) return FALSE;
    else return TRUE;
}


void init(ListType *list) {
    list->length = 0;
    list->head = list->tail = NULL;
};

void add_first(ListType *list, element data) {
    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->data = data;
    if (list->head == NULL) {
        list->head = list->tail = new_node;
        new_node->link = NULL;
    } else {
        new_node->link = list->head;
        list->head = new_node;
    }
    list->length++;
}

void add_last(ListType *list, element data) {
    ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
    new_node->data = data;
    if (list->tail == NULL) {
        list->head = list->tail = new_node; //tail이 null이면 head도 null..
    } else {
        list->tail->link = new_node;
        list->tail = new_node;
    }
    new_node->link = NULL;
    list->length++;
}

void delete_first(ListType *list) {
    ListNode *p = list->head;
    list->head = list->head->link;
    free(p);
    if (list->head == NULL) list->tail = NULL; //...??list비면 tail도 비워줘야함
    list->length--;
}

void delete_last(ListType *list) {
    if (list->tail == NULL) error("there is no Node. error");
    if (list->head == list->tail) {
        //only 1 node in list
        free(list->head);
        list->head = list->tail = NULL;
    } else {
        ListNode *p = list->head;
        while (p->link != list->tail) {
            p = p->link;
        }
        free(list->tail);
        list->tail = p;
        list->tail->link = NULL;
    }
    list->length--;
}

int main() {
    ListType list1;
    init(&list1);
    add_first(&list1, 20);
    add_last(&list1, 30);
    add_first(&list1, 10);
    add_last(&list1, 40);
    add(&list1, 2, 70);
    display(&list1);

    delete_(&list1, 2);
    delete_first(&list1);
    delete_last(&list1);
    display(&list1);

    printf("%s\n", is_in_list(&list1, 20) == TRUE ? "TRUE" : "FALSE");
    printf("%d\n", get_entry(&list1, 0));
}

#include <stdlib.h>
#include <stdio.h>
//
// Created by sinil on 2025-10-10.
//
typedef int element;
//헤드노드가 있다.

typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;

typedef struct {
    DlistNode *top;
} LinkedStackType;

// r = +1 위노드 , l = -1 아래노드라고 가정하자.
void init(LinkedStackType *s) {
    s->top = (DlistNode *) malloc(sizeof(DlistNode)); // 헤드노드 생성 초기화해주는것에 ㅏㄱ까움.
    s->top->llink = s->top;
    s->top->rlink = s->top; // 자기자신을 가리키는 헤드노드만 있는 상태
}

int is_empty(LinkedStackType *s) {
    return (s->top->rlink == s->top);
}

void push(LinkedStackType *s, element item) {
    DlistNode *temp = (DlistNode *) malloc(sizeof(DlistNode));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }
    // 헤드노드 오른쪽에 넣는다)
    temp->data = item;

    temp->llink = s->top;
    temp->rlink = s->top->rlink;

    s->top->rlink->llink = temp;
    s->top->rlink = temp;

    // //? 여기에서 s->top을 옮겨주어야하는가.??? 궁금합니다. s->top = temp로?
    // s->top = temp;
}

element pop(LinkedStackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    int data;

    DlistNode * temp = s->top->rlink;
    data = temp->data;
    temp->rlink->llink = s->top;
    s->top->rlink = temp->rlink;
    free(temp);
    return data;
}

element peek(LinkedStackType *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    } else {
        return s->top->rlink->data;
    }
}

int main() {
    LinkedStackType s;
    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    return 0;
}

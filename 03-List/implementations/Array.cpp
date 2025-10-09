//
// Created by sinil on 2025-10-07.
//

//list using array
#define MAX_LIST_SIZE 10
#include <process.h>
#include <stdio.h>

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}


typedef int element;
typedef struct {
    int list[MAX_LIST_SIZE]; //define array
    int length; // the number of items
}ArrayListType;

void init (ArrayListType *L) {
    L->length = 0;
}

int is_empty(ArrayListType *L) {
    return L->length == 0;
}

int is_full(ArrayListType *L) {
    return L->length == MAX_LIST_SIZE;
}

// 1) 배열이 포화상태인지 확인.(Is saturated?) -> insertion 위치 범위체크
// 2) 삽입 위치 뒤에 items를 한칸씩 뒤로 옮긴다.
void add(ArrayListType *L, int position, element item){
    if (!is_full(L) && (position >=0) &&(position <= L->length)) {
        int i;
        for (i=(L->length-1); i>=position;i--)
            L->list[i+1] = L->list[i]; //한칸씩 뒤로 미룬다. 공간만들어주기
        L->list[position] = item;
        L->length++;
    }
}

// 1) 적절한 index인지 확인 (Confirm whether the index is appropriate)
// 2) 삭제위치 뒤의 items를 한칸씩 앞으로 땡긴다.
element delete_node(ArrayListType *L, int position){
    int i;
    element item;
    if (position<0 || position >= L->length) error("Position error");
    item = L->list[position];
    for (int i = position; i<L->length;i++)
        L->list[i] = L->list[i+1];
    L->length--;
    return item;
}
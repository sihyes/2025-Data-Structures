//
// Created by sinil on 2025-12-05.

#include <stdio.h>

//힙 스켈레톤코드 이용(assignment 6)
typedef struct element{
    int key;
} element;

typedef struct {
    element *heap;
    int heap_size;
} HeapType;

// Initialization
void init(HeapType *h) {
    h->heap_size = 0;
}

// Insert the item at heap h, (# of elements: heap_size)
void insert_max_heap(HeapType *h, element item)
{
    int i;
    i = ++(h->heap_size);

    // The process of comparing with the parent node as it traverses the tree
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; // Insert new node
}

//decrease the element i’s value to ‘key’
void Decrease_key_min_heap(int *A, int i,int key)
{
    if (key >= A[i]) {
        printf("error! new key is not smaller than current key");
        return;
    }
    //Implement your code below. 키가 기존 노드보다 크면 종료!
    A[i] = key;
    while (A[i]<A[i/2] && i>1) {
        int tmp = A[i];
        A[i] = A[i/2];
        A[i/2] = tmp;
        i =  i/ 2;

    }
    }

//Increase the element i’s value to ‘key’
void Increase_key_min_heap(int * A, int i,int key)
{
    if (key <= A[i]) {
        printf("error! new key is not larger than current key");
        return;
    }
    //Implement your code below.
    int n = A[0];  // heap_size
    A[i] = key;
    while (1) {
        // 내가 자식노드보다 작으면 종료, 내아래로 집합.
        // 1)왼쪽오른쪽 자식과 둘다 비교
        int left = 2*i;
        int right = 2*i + 1;
        int new_index = i;

        if (left <= n && A[left] < A[new_index]) new_index = left;
        if (right <= n &&A[right] < A[new_index]) new_index = right;

        if (new_index == i) break;//자기자신

        int tmp = A[i];
        A[i] = A[new_index];
        A[new_index] = tmp;

        i = new_index;
    }

}

void print_heap(int * A) {
    int n = A[0];
    printf("Heap: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int minheap[11] = {10,1,4,2,7,5,3,3,7,8,9};

    printf("default min_heap... original \n");
    print_heap(minheap);

    Increase_key_min_heap(minheap, 3, 10);
    printf("after increase key 2 -> 10 \n");
    print_heap(minheap);

    Decrease_key_min_heap(minheap, 4, 3);
    printf("after decrease key 7 -> 3 \n");
    print_heap(minheap);


    return 0;
}
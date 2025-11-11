//
// Created by sinil on 2025-11-05.
//
// heapsort.cpp : Defines the entry point for the console application.
//


#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include <time.h>
#include <sys/time.h>

#define MAX_ELEMENT 2000
typedef struct element{
	int key;
} element;

typedef struct {
	element *heap;
	int heap_size;
} HeapType;

// Integer random number generation function between 0 and n-1
int random(int n)
{
	return rand() % n;
}

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

// Delete the root at heap h, (# of elements: heap_size)
element delete_max_heap(HeapType *h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// Find a smaller child node
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// Move down one level
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

	void build_max_heap(HeapType *h)
	{
		// Implement this function here.
		//힙은 자료구조 배열을 사용하지.... 즉 자식은 부모*2 [부모 자식1 자식2 자식1-1 자식1-2 자식2-1 자식 2-2 | 1-1-1 | 1-1-2 | 1-2-1] // 뒤에 다섯개가 비교대상
		for (int i= h->heap_size/2; i>=1; i--){
			int parent = i;
			element temp = h->heap[parent];
			while (2*parent <=h->heap_size) {
				int child = 2*parent;
				if ( (child < h->heap_size) && (h->heap[child].key) < h->heap[child+1].key)
					child++; // 17page
				if (temp.key >= h->heap[child].key) break;
				//move dowwn!
				h->heap[parent] = h->heap[child];
				parent = child;
				child *=2;
			}
			h->heap[parent] = temp; //맨처음 잡아놓은 parent의 위치가 어딘지 파악가능!
		}
	}

//input: heap 'h'
//output: sorted element array 'a'
void heap_sort(HeapType *h, element *a, int n)
{
	int i;

	build_max_heap(h);
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
}

bool check_sort_results(element *output, int n)
{
	bool index = 1;
	for(int i=0;i<n-1;i++)
		if (output[i].key > output[i + 1].key)
		{
			index = 0;
			break;
		}
	return index;
}

int main()
{
	time_t t1;
	//Intializes random number generator
	srand((unsigned)time(&t1));

	int input_size = 5000;	//10, 100, 1000
	int data_maxval = 10000;

	HeapType *h1 = (HeapType *)malloc(sizeof(HeapType));
	// 'heap' is allocated according to 'input_size'.  heap starts with 1, so 'input_size+1' is used.
	h1->heap = (element *)malloc(sizeof(element)*(input_size + 1));

	// output: sorted result
	element *output = (element *)malloc(sizeof(element)*input_size);



	// Generate an input data randomly
	for (int i = 0; i < input_size; i++)
		h1->heap[i+1].key = random(data_maxval);	// note) heap starts with 1.
	h1->heap_size = input_size;

	if (input_size < 20){
		printf("Input data\n");
		for (int i = 0; i < input_size; i++)	printf("%d\n", h1->heap[i + 1].key);
		printf("\n");
	}

	struct timeval start, end;
	gettimeofday(&start, NULL);  // 시작 시간

	// Perform the heap sort
	heap_sort(h1, output, input_size);
	gettimeofday(&end, NULL);    // 종료 시간
	double runtime_ms = (end.tv_sec - start.tv_sec)*1000.0 + (end.tv_usec - start.tv_usec)/1000.0;


	if (input_size < 20) {
		printf("Sorted data\n");
		for (int i = 0; i < input_size; i++)	printf("%d\n", output[i].key);
		printf("\n");
	}

	// Your code should pass the following function (returning 1)
	if(check_sort_results(output, input_size))
		printf( "input_size : %d \nSorting result is correct.\n",input_size );
	else
		printf("Sorting result is wrong.\n");

	printf("Runtime: %.3f ms\n", runtime_ms);
	return 0;
}
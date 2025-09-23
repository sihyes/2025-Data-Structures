#include <stdio.h>
#include <stdlib.h>  // malloc, free use
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {
	int row;
	int col;
	int value;
} element;

typedef struct {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
} SparseMatrix;

void swap(int* px, int* py) {
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;	
}

void merge(element arr[], int left, int mid, int right, element tmp[]) {
	int i = left; // left part
	int j = mid + 1; // right part
	int k = left; // tmp index

	while (i <= mid && j <= right) {
		if (arr[i].row <= arr[j].row || (arr[i].row == arr[j].row && arr[i].col < arr[j].col)) {
			tmp[k++] = arr[i++]; // if already, keep going
		}
		else {
			tmp[k++] = arr[j++]; // if not already, back is setted.
		}
	}

	while (i <= mid) tmp[k++] = arr[i++];
	while (k <= right) tmp[k++] = arr[j++];

	//tmp -> arr 복사
	for (i = left; i <= right; i++) { arr[i] = tmp[i]; }

}

void mergeSort(element arr[], int left, int right, element tmp[]) { //ascending order
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(arr, left, mid, tmp);
		mergeSort(arr, mid + 1, right, tmp);
		merge(arr, left, mid, right, tmp);
	}
}

SparseMatrix transpose(SparseMatrix B) {
	SparseMatrix A=B;
	A.rows = B.cols;
	A.cols = B.rows;
	for (int i = 0; i < A.terms; i++) {
		swap(&A.data[i].row, &A.data[i].col);
	}

	element tmp[MAX_TERMS];
	mergeSort(A.data, 0, A.terms - 1, tmp);

	return A;
	
}

int** denseMatrix(SparseMatrix B) {
	int** dense = (int**)malloc(sizeof(int*) * B.rows);
	for (int i = 0; i < B.rows; i++)
		dense[i] = (int*)malloc(sizeof(int) * B.cols);

	// 0으로 초기화
	for (int i = 0; i < B.rows; i++)
		for (int j = 0; j < B.cols; j++)
			dense[i][j] = 0;

	// SparseMatrix 값 채우기
	for (int k = 0; k < B.terms; k++)
		dense[B.data[k].row][B.data[k].col] = B.data[k].value;

	return dense;
}



int main() {
	//Add B as an input. Use your own example freely
	SparseMatrix B = {
		{
			{0,3,7},
			{1,0,9},
			{1,5,8},
			{3,0,6},
			{3,1,5},
			{4,5,1},
			{5,2,2}
		}, 6,6,7
	};

	//perform the transpose operation
	SparseMatrix A = transpose(B);

	//print out B and B^T in a dense matrix form to check 
	//whether the operation works correctly
	int** dense = denseMatrix(B);

	for (int i = 0; i < B.rows; i++) {
		for (int j = 0; j < B.cols; j++) {
			printf("%d ", dense[i][j]);
		}
		printf("\n");
	}

	printf("=======================================\n");

	int** dense2 = denseMatrix(A);
	for (int i = 0; i < A.rows; i++) {
		for (int j = 0; j < A.cols; j++) {
			printf("%d ", dense2[i][j]);
		}
		printf("\n");
	}





	for (int i = 0; i < B.terms; i++) {
		printf("(%d, %d) = %d\n", B.data[i].row, B.data[i].col, B.data[i].value);
	}
	printf("============\n");

	
	for (int i = 0; i < A.terms; i++) {
		printf("(%d, %d) = %d\n", A.data[i].row, A.data[i].col, A.data[i].value);
	}

	for (int i = 0; i < B.rows; i++) {
		free(dense[i]);
		free(dense2[i]);
	}
	free(dense);
	free(dense2);
	return 0;

}

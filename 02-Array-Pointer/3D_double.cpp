#include <stdlib.h>
#include<stdio.h>


double*** memoryAllocate(int x, int y, int z) {
	double*** A = (double***)malloc(sizeof(double**) * x);
	for (int i = 0; i < x; i++) {
		A[i] = (double**)malloc(sizeof(double*) * y);
		for (int j = 0; j < y; j++) {
			A[i][j] = (double*)malloc(sizeof(double) * z);
		}
	}

	return A;
}

double*** addition3DArray(double*** A, double*** B, double*** C,int x, int y, int z) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				C[i][j][k] = A[i][j][k] + B[i][j][k];
			}
		}
	}
	return C;
}

void deallocate(double*** A,int x,int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			free(A[i][j]);
		}
		free(A[i]);
	}
	free(A);

}

void confirmPrint(double*** A, int x, int y, int z) {
	for (int i = 0; i < x; i++) {
		printf("Matrix %d:\n", i);
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++)
				printf("%lf ", A[i][j][k]);
			printf("\n");
		}
		printf("\n");
	}
}




int main() {
	//define two matrices A and B using 'mem-alloc-3D-double';
	int x=3, y=3, z=3;
	double*** A = memoryAllocate(x, y, z);
	double*** B = memoryAllocate(x, y, z);

	//perform addition of two matrices using 'addition_3D'
	double*** C = memoryAllocate(x, y, z);

	// initialize value
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				A[i][j][k] = i + j + k;                // example
				B[i][j][k] = (i + 1) * (j + 1) * (k + 1); // example
			}
		}
	}


	addition3DArray(A, B, C, x, y, z);


	// print
	printf("Matrix A:\n");
	confirmPrint(A, x, y, z);

	printf("Matrix B:\n");
	confirmPrint(B, x, y, z);

	printf("Matrix C (A+B):\n");
	confirmPrint(C, x, y, z);



	//deallocate A and B
	deallocate(A,x,y);
	deallocate(B,x,y);
	deallocate(C,x,y);

	return 0;
	
}

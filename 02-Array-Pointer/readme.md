code1 is about SparseMatrix.

### **Structures**
- `element { row,col,value}` 
Represents one non-zero element of the matrix.
=> `A[row][col] = value` 

`SparseMatrix {element data[MAX_TERMS],rows,cols,terms}`
Represents a SparseMatrix
- `data[MAX_TERMS]` stores all non-zero elements.
- `rows` & `cols` size of the original matrix.
- `terms` number of non-zero values.

### **Functions**
- `swap` 
Swap two integer values using pointers.

- `merge(element arr[], int left, int mid, int right, element tmp[])`  
Merge two sorted subarrays (arr[left..mid] and arr[mid+1..right]) into one sorted array.
Sorting rule:
 1. Primary key → row (ascending)
 2. Secondary key → col (ascending if rows are equal)

- `mergeSort(element arr[], int left, int right, element tmp[])`  
Recursively split the array into subarrays until size = 1.
Then merge back with 'merge' in ascending order.
Guarantees all elements are sorted by row and column.

- `transpose(SparseMatrix B)`  
Returns the transpose of matrix B:
 1. Swap row and col of each element.
 2. Sort elements again using mergeSort.

- `denseMatrix(SparseMatrix B)`  
Convert sparse matrix into a full 2D dense array.
Non-zero values are placed at their positions, others are filled with 0.


**Merge Sort**
Time Complexity: O(n log n) (efficient for large datasets).
- Merge Sort is a **divide-and-conquer algorithm**:
  1. Divide the array into two halves.
  2. Recursively sort each half.
  3. Merge the sorted halves into a single sorted array.
- The recursion stops when `left >= right` (subarray has one element).

------------------------------------------------------------------------------------------
code 2 is about Dynamic Memory Allocaion
(When 3D Array, type of each element is double)

### **Functions**

- `double*** memoryAllocate(int x, int y, int z) `
Allocate memory for a 3D array. ('double' type).
Return pointer which points to the 3D array.

- `double*** addition3DArray(double*** A, double*** B, double*** C,int x, int y, int z)`
Take two 3D arrays A and B, add them element by element.
Store result in array C. 
Return C.

- `void deallocate(double*** A,int x,int y)`
Free the memory allocated for array A.
Need x and y for correct deallocation of all layers.

- `void confirmPrint(double*** A, int x, int y, int z)`
Print all elements of the 3D array.
Used for checking (validation purpose).

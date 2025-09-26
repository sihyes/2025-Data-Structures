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

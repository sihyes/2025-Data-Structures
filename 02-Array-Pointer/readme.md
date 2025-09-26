# Sparse Matrix & 3D Array Operations in C++

code1(sparsematrix.cpp) performs make sparseMatrix and transpose from its original matrix, and then finally make transposed version's matrix to sparse matrix.

code2(3D_Double.cpp) performs operations on sparse matrices to reduce memory usage.nsusing memory efficiently.

## development Environment
- OS: Windows 11
- IDE: CLion 2025.2.2
- Language: C
- Compiler: MinGW (MSYS2 base)
- Build System: CMake

## Installation
1. Install CLion
2. Install MinGW and add its `bin` directory to your system PATH
3. Open the project folder in CLion


## Compile & Build
This project uses CMake. Each executable corresponds to a specific source file.
- CMake target defined in `CMakeLists.txt`:

```cmake
add_executable(2025_Data_Structures
        02-Array-Pointer/sparsematrix.cpp)
```
1. Open the project in CLion
2. Click Build -> Build Project or press Ctrl+F9
3. After building, the executable will appear in cmake-build-debug or cmake-build-release folder

Note: If you want to run 3D_double.cpp, you need to modify CMakeLists.txt:
```cmake
add_executable(3D_double_exec
        3D_double.cpp)
```
Then rebuild the project to create a new executable.


## Running the Program
 In CLion, click Run -> Run `'2025_Data_Structures'` or press `Shift+F10`

 ## Notes
 Each executable corresponds to a specific source file.
adjust `CMakeLists.txt` if you want to run a different file.


## Appendix
For detailed explanations of structures, functions, and algorithms used in each program, please refer to the `DOC` folder:

- Sparse Matrix operations → `DOC/SparseMatrix.md`
- 3D Array operations → `DOC/3D_Array.md`

# Linked List Implementations in C

This project contains several C programs that implement and manipulate linked lists, including singly linked lists and doubly linked lists. The main focus is on understanding list operations, memory management, and practical implementation of data structures discussed in lectures.

## Code Overview

1. **DlinkedlistInsertion.cpp**  
   Implements a doubly linked list with functions to insert nodes at the beginning, end, or any position. Demonstrates how `dinsert_node()` can handle both front and rear insertions using a head node.

2. **MergeLinkedList.cpp**  
   Implements merging of two sorted singly linked lists into a new sorted list. Includes functions to create lists from arrays and merge them while maintaining ascending order. The time complexity of the merge operation is Θ(n), where n is the total number of elements in the two lists.

3. **ListADT.cpp**  
   Implements a singly linked list with a `ListType` structure keeping track of head, tail, and length. Re-implements all List ADT functions from the lecture notes, as well as `add_first`, `add_last`, `delete_first`, and `delete_last`. Handles memory allocation and deallocation properly to prevent leaks.

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

1. Open the project in CLion
2. Click Build -> Build Project or press Ctrl+F9
3. After building, the executable will appear in cmake-build-debug or cmake-build-release folder

Note: If you want to run some `.cpp`, you need to modify CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 4.0)
project(2025_Data_Structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(2025_Data_Structures
        03-List/DlinkedlistInsertion.cpp)
```
```cmake
add_executable(2025_Data_Structures
        03-List/MergeLinkedList.cpp)
```

```cmake
add_executable(2025_Data_Structures
                    03-List/ListADT.cpp
)
```
Then rebuild the project to create a new executable.


## Running the Program
 In CLion, click Run -> Run `'2025_Data_Structures'` or press `Shift+F10`

 ## Notes
 Each executable corresponds to a specific source file.
adjust `CMakeLists.txt` if you want to run a different file.


## Appendix
For detailed explanations of the structures, functions, and algorithms used in each program, please visit my blog: 

Link1 : [Technical report](https://sihyes.tistory.com/116)

Link2 : [List](https://sihyes.tistory.com/117)

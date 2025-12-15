# Data Structures: Hashing & BST Sorting
This project covers the implementation of two fundamental data structures: **Hash Tables with Chaining** and **Binary Search Trees (BST)**. It focuses on efficient data management through deletion and sorting operations.

## Code Overview

1. Hash Table Deletion (Chaining)
`code1_hashing_deletion.cpp` – **Collision Handling via Chaining**

* Logic: Implements a hash table where each bucket is a linked list (chaining).
* Implementation Point: 
  * The `hash_chain_delete` function performs a standard linked-list deletion. It ensures that the chain remains connected by relinking the `node_before->link` to the `node->link` `before freeing memory.
* Key Operation: Handles both "head node deletion" and "middle/tail node deletion" cases to prevent memory leaks.

2. BST Sort (Iterative Insertion & In-order Traversal)
   `code2_bst_sorting.cpp` – **Sorting 1,000 Random Integers**

* **Logic**: Generates 1,000 random integers and inserts them into a Binary Search Tree.
* **Implementation Point**:
  * Iterative Insertion: Uses a `while` loop and a parent pointer to insert nodes, ensuring memory efficiency compared to recursion.
  * Duplicate Handling: Allows duplicates by pushing equal values to the right subtree `(key >= p->key)`.
  * In-order Traversal: Performs a `Left -> Root -> Right` traversal to print all elements in ascending order.

## Development Environment

* **OS:** Windows 11
* **IDE:** CLion 2025.2.2
* **Language:** C
* **Compiler:** MinGW (MSYS2 base)
* **Build System:** CMake



## Installation

1. Install **CLion**
2. Install **MinGW** and add its `bin` directory to your system `PATH`
3. Open this project folder in CLion



## Compile & Build

This project uses CMake. Each executable corresponds to a specific source file. - CMake target defined in CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 4.0)
project(2025_Data_Structures)
set(CMAKE_CXX_STANDARD 14)

# Run code1.cpp
add_executable(2025_Data_Structures 09-HashingSearch/code1.cpp)
```

To run another file, simply replace it:

```cmake
# Run code2.cpp
add_executable(2025_Data_Structures 09-HashingSearch/code2.cpp)
```

Then **Build → Build Project (Ctrl+F9)** to compile.



## Running the Program

In CLion:
Click **Run → Run ‘2025_Data_Structures’** or press **Shift+F10**
The output window will display inorder traversal results before and after operations, verifying correctness.



## Notes


Each executable corresponds to a specific source file.
adjust `CMakeLists.txt` if you want to run a different file.



## Appendix

For detailed analysis and theory behind these implementations, visit my blog:

* **Link1:** [Assignment09 Technical Report](https://sihyes.tistory.com/174)


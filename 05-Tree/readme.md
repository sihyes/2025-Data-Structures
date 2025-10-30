# Binary Search Tree (BST) Implementations in C

This project contains three C programs that implement and manipulate **Binary Search Trees (BST)**.
Each program focuses on key operations such as finding successors and predecessors in inorder traversal, and revising deletion logic accordingly.
Through this project, you can deepen your understanding of **tree traversal**, **node linking**, and **deletion cases** in BSTs.


## Code Overview

1. **`code1.cpp` – Find Successor in Inorder Traversal**
   Implements a function that finds the **successor** of a given node in an inorder traversal.

   * If the node has a right subtree, the successor is the **leftmost node** in that right subtree.
   * If the node has no right subtree, the successor is found by traversing upward through the parent pointer until a node that is a **left child of its parent** is encountered.
     Demonstrates the concept of **inorder successor search** using parent pointers in a BST.

2. **`code2.cpp` – Find Predecessor in Inorder Traversal**
   Implements a function that finds the **predecessor** of a given node in an inorder traversal.

   * If the node has a left subtree, the predecessor is the **rightmost node** in that left subtree.
   * If the node has no left subtree, the predecessor is found by traversing upward through the parent pointer until a node that is a **right child of its parent** is encountered.
     Reinforces understanding of **inorder predecessor relationships** within BST structures.

3. **`code3.cpp` – BST Deletion using Inorder Predecessor**
   Revises the original deletion algorithm (from textbook p.60–61), which handled **Case 3** using the inorder successor from the right subtree.
   In this version, **Case 3** is implemented using the **inorder predecessor** from the left subtree instead.

   * The program verifies correctness by running three test examples and ensuring the outputs match the original implementation’s results.
     Demonstrates flexibility in BST deletion and highlights the symmetric relationship between successor- and predecessor-based deletion strategies.



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
add_executable(2025_Data_Structures 05-Tree/code1.cpp)
```

To run another file, simply replace it:

```cmake
# Run code2.cpp
add_executable(2025_Data_Structures 05-Tree/code2.cpp)
```

```cmake
# Run code3.cpp
add_executable(2025_Data_Structures 05-Tree/code3.cpp)
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

* **Link1:** [Assignment05 Technical Report](https://sihyes.tistory.com/133)
* **Link2:** [[자료구조] 트리. Tree](https://sihyes.tistory.com/136)


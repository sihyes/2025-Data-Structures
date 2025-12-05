# Sorting Algorithms in C

This project aims to implement **Min-Heap-based operations (decrease-key/increase-key)** and **Prim algorithm (MST)** in C language to practice the principle of operation of hip structures and the process of calculating graph-minimal spanning trees.
Both programs are designed to experience the core concepts covered in the data structure class as actual code structures.

## Code Overview

`code1_minheap_decrease_increase_key.cpp` – **Min-Heap** `decrease-key` / `increase-key`
Implements correct bubble-up (`decrease-key`) and heapify-down (`increase-key`) operations for a 1-indexed array-based min-heap.

`code2_prim_algorithm.cpp` – **Prim’s MST using Min-Heap**
Implements Prim’s algorithm with a min-heap (build, delete-min, decrease-key) and `selected[]` to produce the MST from an adjacency matrix.

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
add_executable(2025_Data_Structures 08-Graph/code1.cpp)
```

To run another file, simply replace it:

```cmake
# Run code2.cpp
add_executable(2025_Data_Structures 08-Graph/code2.cpp)
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

* **Link1:** [Assignment08 Technical Report](https://sihyes.tistory.com/164)


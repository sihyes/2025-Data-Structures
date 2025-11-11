# Sorting & Compression Algorithms in C

This project contains two C programs that implement and analyze Heap Sort and Huffman Coding.
Each program focuses on understanding data structure mechanics and algorithmic efficiency, particularly how binary trees can be used for sorting and compression.
Through this project, you can deepen your understanding of array-based heaps, binary tree traversal, and bit-level encoding/decoding techniques.
## Code Overview

1. **`code1.cpp` – Heap Sort Implementation**
    Implements the **Heap Sort** algorithm using an array-based binary heap.
   * The program first constructs a max heap, ensuring that each parent node is greater than its children.
   * It then repeatedly swaps the root with the last element and restores the heap property through a downheap (heapify) process.
   * This implementation efficiently utilizes index relationships within a complete binary tree structure to manage parent–child relationships.
   * The runtime was measured in milliseconds to observe performance trends as input size increased. The results confirmed that execution time grows approximately in proportion to n log n, consistent with the theoretical time complexity of Heap Sort.
2. **`code2.cpp` – Huffman Encoding and Decoding**
   Implements **Huffman Coding**, a lossless compression algorithm based on variable-length encoding.
   * A Huffman tree is built according to character frequency.
   * The lookup table (m_LUT) stores the binary code assigned to each character during tree traversal.
   * Encoding replaces each character in the input string with its corresponding Huffman code to generate a bitstream.
   * Decoding traverses the Huffman tree according to each bit (left for 0, right for 1) until reaching a leaf node, reconstructing the original string.
   * This program demonstrates how character frequency can be used to achieve efficient data compression, similar to real-world applications like JPEG and ZIP.


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
add_executable(2025_Data_Structures 06-Priority/code1.cpp)
```

To run another file, simply replace it:

```cmake
# Run code2.cpp
add_executable(2025_Data_Structures 06-Priority/code2.cpp)
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

* **Link1:** [Assignment06 Technical Report](https://sihyes.tistory.com/142)
* **Link2:** [[자료구조] Priority, Heap](https://sihyes.tistory.com/140)


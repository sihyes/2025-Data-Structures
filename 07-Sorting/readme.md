# Sorting Algorithms in C

This project contains two C programs that implement and analyze Stable Selection Sort and 24-bit Radix Sort.
Each program focuses on understanding how stability, bit-level segmentation, and algorithmic structure affect sorting correctness and performance.

Through this project, you can deepen your understanding of stable sorting mechanisms, digit-based sorting, counting arrays, and pointer-level optimizations for high-performance algorithms.
## Code Overview

1. **`code1.cpp` – Stable Selection Sort Implementation** <br>
   Implements a stable variant of Selection Sort, ensuring that equal values preserve their relative order.
   * Unlike traditional Selection Sort (which swaps the smallest element with the front), this implementation shifts elements instead of swapping.
   * For each index, the algorithm:
     * Finds the smallest element in the remaining range. 
     * Stores the value temporarily. 
     * Shifts all intermediate elements to the right by one position. 
     * Inserts the smallest element into the correct index.
   * Because it does not perform destructive swaps, this version guarantees full stability. 
   * Although still O(n²) in time complexity, this version clearly demonstrates how stability can be preserved by using controlled element shifting rather than direct swapping.

   
2. **`code2.cpp` – 24-bit Radix Sort (6-bit × 4 Segmenting)** <br>
   Implements Radix Sort for 24-bit integers by splitting each number into four 6-bit segments.
   * Each 24-bit value is decomposed into four digits, Extracted using:
```
(value >> (6 * d)) & 0x3F
```
   * Sorting is performed from the Least Significant Digit (LSD) upward.
   * Each stage uses a stable Counting Sort, consisting of:
     * Histogram (count array of size 64)
     * Prefix sum accumulation 
     * Stable placement (iterate from the end)
   * To maximize efficiency, the algorithm uses pointer swapping rather than copying arrays after each pass:
```
data *swap = A;
A = tmp;
tmp = swap;
```
This allows each Sorting stage to reuse buffers without unnecessary data movement.

   * The final output is validated against the C standard library qsort to ensure correctness.


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
add_executable(2025_Data_Structures 07-Sorting/code1.cpp)
```

To run another file, simply replace it:

```cmake
# Run code2.cpp
add_executable(2025_Data_Structures 07-Sorting/code2.cpp)
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

* **Link1:** [Assignment07 Technical Report](https://sihyes.tistory.com/144)
* **Link2:** [[자료구조] Sotring](https://sihyes.tistory.com/143)


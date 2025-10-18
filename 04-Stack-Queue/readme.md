# Linked List Implementations in C

This project contains several C programs that implement and manipulate various linked list and queue-based structures. <br>
The focus is on understanding node connections, list traversal, queue management, and how linked structures can be used to simulate real-world problems such as customer service scheduling.
## Code Overview

1. **`DoublyLinkedStack.cpp`**  
   Implements a **stack** using **a circular doubly linked list**.
   Demonstrates stack operations (`push`, `pop`, `peek`) based on the LIFO (Last-In First-Out) principle.
   The implementation highlights pointer manipulation in both directions (`leftlink`, `rightlink`) and uses a head node to simplify insertion and deletion.

2. **`TwoBankStaffSimulation.cpp`**  
   Simulates **a bank service system** using a **queue** to manage customers.
   Each customer is represented as a struct with arrival and service time, and two bank staff members handle customers concurrently.
   The simulation calculates metrics such as total served customers, total wait time, and average waiting time.
   Demonstrates how real-time queues and service scheduling can be modeled using data structures in C

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
        04-Stack-Queue/DoublyLinkedStack.cpp)
```
To run a different file:
```cmake
add_executable(2025_Data_Structures
        04-Stack-Queue/TwoBankStaffSimulation.cpp)
```
Then rebuild the project to create a new executable.


## Running the Program
In CLion, click Run -> Run `'2025_Data_Structures'` or press `Shift+F10`

## Notes
Each executable corresponds to a specific source file.
adjust `CMakeLists.txt` if you want to run a different file.


## Appendix
For detailed explanations of the structures, functions, and algorithms used in each program, please visit my blog:

- **Link1** : [Assignment04_Technical report](https://sihyes.tistory.com/118)

- **Link2** : [[자료구조] Stack, Queue](https://sihyes.tistory.com/129)

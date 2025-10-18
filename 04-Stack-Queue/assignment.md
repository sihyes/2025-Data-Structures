In this assignment, two different implementations are required:

#1.(Programming) <br>
The attached code (`linked_stack.cpp`) was implemented using simple linked list. <br>
Re-implement the functions in the code using `circular doubly linked list` which is defined as below, and then run the main function of the code. 

``` C++
typedef struct DlistNode {
    element data;
    struct DlistNode *llink;
    struct DlistNode *rlink;
} DlistNode;
```

#2. (Programming) <br>
The attached code (`Simulation.cpp`) was implemented with the assumption that there is a single bank staff. <br> 
Revise the code accordingly in case that **two bank staffs work**, and then print out the results using `print_stat()` in the code. Note) <br>
A relatively large should be set to obtain meaningful results.
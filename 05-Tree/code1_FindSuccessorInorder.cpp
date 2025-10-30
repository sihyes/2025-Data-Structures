//
// Created by sinil on 2025-10-21.
//

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right, *parent;
} TreeNode;


//                    G
//           C                 F
//       A       B        D        E
TreeNode n1 = {'A',NULL, NULL, NULL};
TreeNode n2 = {'B',NULL, NULL, NULL};
TreeNode n3 = {'C',&n1, &n2, NULL};
TreeNode n4 = {'D',NULL, NULL, NULL};
TreeNode n5 = {'E',NULL, NULL, NULL};
TreeNode n6 = {'F',&n4, &n5, NULL};
TreeNode n7 = {'G',&n3, &n6, NULL};
TreeNode *exp = &n7;

TreeNode * tree_successor(TreeNode *x) {
    TreeNode *y;
    if (x->right != NULL) {
        y = x->right;
        while (y->left) // 중요. 그 다음노드가 null값이 되면안됑~
            y= y->left;
        return y;//go to the leftmost node! starting point
    }
    // x's right subtree is null?
    y = x->parent;
    while (y!=NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

int main() {
    TreeNode *q = exp;
    n1.parent = &n3;
    n2.parent = &n3;
    n3.parent = &n7;
    n4.parent = &n6;
    n5.parent = &n6;
    n6.parent = &n7;

    while (q->left) q= q->left; //go to the leftmost node! starting point
    do {
        printf("%c \n", q->data); //output data
        //call the successor
        q=tree_successor(q);
    }while (q); // if not null!
}

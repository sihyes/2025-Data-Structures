//
// Created by sinil on 2025-12-15.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. ㅌ트리노드 구조체 정의
typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

// 새 노드 생성 함수
TreeNode* create_node(int key) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}
// 2. BST 삽입 함수 iteratively!
void insert_iterative(TreeNode** root, int key) {
    TreeNode* p = NULL;       // 부모 노드를 추적
    TreeNode* t = *root;      // 현재 탐색 노드
    TreeNode* new_node;              // 새로 생성할 노드
    // 새 노드 생성
    new_node = create_node(key);

    // 1. 삽입할 위치 탐색
    while (t != NULL) {
        p = t; // 현재 노드를 부모로 설정하고 아래로 이동
        if (key < t->key)
            t = t->left;
        else
            t = t->right; // 중복 값도 오른쪽으로 이동
    }

    // 3. 트리가 비어있었다면 루트로 설정
    if (p == NULL)
        *root = new_node;
    else {
        // 부모 노드와 뉴 노드 연결
        if (key < p->key)
            p->left = new_node;
        else
            p->right = new_node;
    }
}

// 3. 중위 순회 (In-order Traversal)
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);       // 왼
        printf("%d ", root->key);  // 루트
        inorder(root->right);      // 오른
    }
}
int main() {
    int input_size = 1000;
    int data_maxval = 10000;
    TreeNode* root = NULL;

    //시드 시간으로
    srand(time(NULL));

    // 공간을 할당해줘용
    int* input = (int*)malloc(sizeof(int) * input_size);

    printf("Generating and inserting 1000 random numbers...\n");
    for (int i = 0; i < input_size; i++) {
        input[i] = rand() % data_maxval; // 0 ~ 9999 사이 난수
        insert_iterative(&root, input[i]);   // 즉시 BST에 삽입
    }

    // 4. 결과 출력
    printf("\nSorted Results (In-order Traversal):\n");
    inorder(root);
    printf("\n");

    free(input);
    return 0;
}
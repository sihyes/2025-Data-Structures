//
// Created by sinil on 2025-12-05.
//
#include <stdio.h>

#define MAX_VERTICES 8
#define INF 1000

// 문제에서 주어진 그래프
int weight[MAX_VERTICES][MAX_VERTICES] = {
 {0,3,INF,INF,INF,INF,INF,14},
 {3,0,8,INF,INF,INF,INF,10},
 {INF,8,0,15,2,INF,INF,INF},
 {INF,INF,15,0,INF,INF,INF,INF},
 {INF,INF,2,INF,0,9,4,5},
 {INF,INF,INF,INF,9,0,INF,INF},
 {INF,INF,INF,INF,4,INF,0,6},
 {14,10,INF,INF,5,INF,6,0}
};

// ======== 전역 변수 ========
int heap[100];   // min heap (vertex 번호 저장)
int pos[100];    // vertex -> heap index
int dist[MAX_VERTICES];
int parent[MAX_VERTICES];

// ======== 도우미 함수 ========
void swap_heap(int i, int j){
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;

    pos[heap[i]] = i;
    pos[heap[j]] = j;
}

// ======== 최소 힙 구성 ========
void build_min_heap(int n){
    for(int i=n/2;i>=1;i--){
        int p=i;
        while(1){
            int left=2*p;
            int right=2*p+1;
            int smallest=p;

            if(left<=n && dist[heap[left]]<dist[heap[smallest]]) smallest=left;
            if(right<=n && dist[heap[right]]<dist[heap[smallest]]) smallest=right;

            if(smallest==p) break;
            swap_heap(p,smallest);
            p=smallest;
        }
    }
}

// ======== 최소값 삭제 ========
int delete_min_heap(int *size){
    int root = heap[1];
    heap[1] = heap[*size];
    pos[heap[1]] = 1;
    (*size)--;

    int p=1;
    while(1){
        int left=2*p;
        int right=2*p+1;
        int smallest=p;

        if(left<=*size && dist[heap[left]]<dist[heap[smallest]]) smallest=left;
        if(right<=*size && dist[heap[right]]<dist[heap[smallest]]) smallest=right;

        if(smallest==p) break;

        swap_heap(p,smallest);
        p=smallest;
    }
    return root; // 최솟값 vertex 번호 반환
}

// ======== decrease-key ========
void decrease_key_min_heap(int v){
    int i = pos[v];

    while(i>1){
        int p = i/2;
        if(dist[heap[p]] <= dist[heap[i]]) break;

        swap_heap(p,i);
        i = p;
    }
}

// ======== PRIM 알고리즘 ========
void prim(int start){
    int i;
    int heap_size = MAX_VERTICES;
    int selected[MAX_VERTICES] = {0};  // ★ 추가 ★

    // 초기화
    for(i=0;i<MAX_VERTICES;i++){
        dist[i] = INF;
        parent[i] = -1;

        heap[i+1] = i;
        pos[i] = i+1;
    }

    dist[start] = 0;

    build_min_heap(heap_size);

    while(heap_size > 0){

        int u = delete_min_heap(&heap_size);

        selected[u] = 1;   // 방문 표시

        for(int v=0; v<MAX_VERTICES; v++){

            if (!selected[v] && weight[u][v] != INF && weight[u][v] < dist[v]) {

                dist[v] = weight[u][v];
                parent[v] = u;

                decrease_key_min_heap(v);
            }
        }
    }
}

// ======== MST 출력 ========
void print_prim(){
    for(int v=0; v<MAX_VERTICES; v++){
        if(parent[v] != -1){
            printf("Vertex %d -> %d     edge: %d\n",
                parent[v], v, dist[v]);
        }
    }
}

// ======== MAIN ========
int main(){
    printf("=== Prim Algorithm Using Min Heap ===\n\n");

    prim(0); // start at vertex 0

    printf("=== MST Result ===\n");
    print_prim();

    return 0;
}

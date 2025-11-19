//
// Created by sinil on 2025-11-14.
//

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <time.h>



typedef struct data {
    unsigned int value; // (원래 값)
    unsigned int seg; // 현재 sorting segment 값 (0~63)
} data;

unsigned int random24() {
    // 24비트 랜덤 숫자를 생성합니다.
    return (unsigned int) (rand() & 0b111111111111111111111111); // 마스크 길이를 24개로.
}

unsigned int getSeg(unsigned int value, int d) {
    return (value >> (6 * d)) & 0b111111; // d가 0,1,2,3 으로가면서6비트씩 읽어나가요)
}

void counting_sort(data *A, data *output, int n) {
    int count[64] = {0};

    //1. 히스토그램
    for (int i = 0; i < n; i++) {
        count[A[i].seg] += 1; // 히스토그램, 즉 각 세그먼트별 개수를 모아요
    }

    //2. 누적합
    for (int i = 1; i < 64; i++) {
        count[i] += count[i - 1];
    }

    // 3. stable sort (뒤에서부터!)
    for (int i = n-1; i >=0; i--) {
        //각 세그먼트를 기존 배열에 다시 위치를 재조정해서 배치해보아요. seg기준으로!
        int s = A[i].seg;
        output[count[s]-1]=A[i];
        count[s]--;
    }
}

void RadixSort(unsigned int * array, int n) {
    //수의 배열과, 분할할 비트수를 받아옵니다.
    data *A = (data *)malloc(sizeof(data) * n);
    data *tmp = (data *)malloc(sizeof(data) * n);

    if (!A || !tmp) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    //원본 값을 복사
    for (int i=0; i<n; i++) {
        A[i].value = array[i];
    }

    // LSD segment부터 네번 처리하면된다.
    for (int s = 0; s < 4; s++) {
        //segment 설정
        for (int i=0; i<n; i++) {
            A[i].seg = getSeg(A[i].value,s); // segment를 받아온다. 원래값주고 몇번째 세그먼트(몇번 shift할건지)
        }

        counting_sort(A,tmp,n);

        data *swap = A; // 포인터를 바꾼다. 즉, 특정 변수명에 담긴 주소를 스윗치~
        A = tmp;
        tmp = swap;
    }
    for (int i=0; i<n; i++) {
        array[i]=A[i].value; // 값들을 다시저장한다.
    }
}
int cmp(const void *a, const void *b) {
    unsigned int x = *(unsigned int *)a;
    unsigned int y = *(unsigned int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int i;
    int n = 1000;
    srand(time(NULL)); // 시드 초기화

    unsigned int *list = (unsigned int *)malloc(sizeof(unsigned int) * n);
    unsigned int *correct = (unsigned int *)malloc(sizeof(unsigned int) * n);

    if (!list || !correct) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    //generate input data using random numbers (0~2^24 - 1)
    for (i = 0; i < n; i++) {
        list[i] = random24();
    }

    // 정답배열 만들기
    memcpy(correct, list, sizeof(unsigned int) * n);
    qsort(correct, n, sizeof(unsigned int), cmp);

    RadixSort(list, n);

    // 둘을 비교 시스템이 해준 정렬vsRadix Sort
    for (i=0; i<n; i++){
        if(correct[i] != list[i]) {
            printf("Mismatch at %d!\n", i);
            return 0;
        }
    }
    printf("Correct!\n");

    free(list);
    free(correct);

    //24비트의 양수를, 4개의 segment로 쪼갭니다. 각 세그먼트는 6비트로 이루어집니다.
    //24비트->6비트*4로 나눈 것 중, 각각의 세그먼트에 대해 6비트의 묶음들끼리 정렬을 시킵니다.
    //LSD(일의자리 숫자부터) 정렬을 해나갑니다.
    //✅ 1. 비트 쉬프트 연산자란?
    //<<	왼쪽 쉬프트 (비트를 왼쪽으로 밀기), x << n x를 왼쪽으로 n비트 이동 오른쪽을 0으로 채웁니다.
    //>>	오른쪽 쉬프트 (비트를 오른쪽으로 밀기)
    // 비트를 쪼갠다. (값 >> 이동량) & 마스크
    // 우리의 경우 6비트를 이용하므로 6자리, 111111을 이용한다. 0011 1111 ,, 16진수로 나타내자면 0x3F
    // 처음 6비트| 값 & 0x3F
    // 다음 6비트 ( 값 >> 6 ) 0x3F
    // 세그먼트에 따라서 순차적으로 정렬 한다!
    // n=1000, b=24, r=6, b/r=4 (# of digits)
    // RadixSort(A, d)
    //     for i=1 to d
    //         Counting Sort(A) on digit i


    //카운팅 소트를 하려면 그럼, 리스트가 4개 필요하고, 임시 리스트(누적합사용, 최종 리스트)가 있어야하는가요?
    // >> 아니다. 원본배열 -> 하위6비트 정렬 -> 그다음 6비트 -> 그다음 -> 마지막 상위 6비트 정렬 -> 최종적으로 정렬완료!
    // 원본 배열과, 아웃풋 배열만 있으면된다!


    return 0;
}

#include <stdio.h>

int main(void) {
    // 실수 변수 선언 & 초기화
    float A = 10.5F;
    float B = 20.6F;

    // 포인터 변수 선언
    float *pA = &A;
    float *pB = &B;

    // 임시로 값을 저장할 공간 생성
    float memory;

    memory = *(pA);
    *(pA) = *(pB);
    *(pB) = memory;

    // 결과 확인
    printf("A: %f\n", A);
    printf("B: %f\n", B);
    
    printf("&A: %p\n", &A);
    printf("&B: %p\n", &B);
    printf("&pA: %p\n", &pA);
    printf("&pB: %p\n", &pB);

    return 0;
}
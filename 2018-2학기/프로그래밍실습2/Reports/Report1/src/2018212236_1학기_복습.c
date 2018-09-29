#include <stdio.h>

int first();
int second();
int third();
int fourth();

int main() {

    puts("\n1, 입출력 그리고 변수 : 자기소개와 사칙연산\n");
    first();

    puts("\n2, 자료형 : 문자의 대소문자 변경\n");
    second();

    puts("\n3, 관계-증감연산자의 이해 : 증감연산자의 퍼즐, 삼항연산자의 선택\n");
    third();

    puts("\n4, 논리연산자와 반복문 : 나를 속이는 거짓말\n");
    fourth();

    return 0;
}

int first() {
    puts("학번:\t2018212236");
    puts("이름:\t김동주");


    float n1, n2;

    n1 = 96.59875;
    n2 = 14.00712;


    printf("n1: %f\nn2: %f\n", n1, n2);

    // 합
    float n_sum = n1 + n2;
    printf("n1 + n2 = %f\n", n_sum);

    // 차
    float n_sub = n1 - n2;
    printf("n1 - n2 = %f\n", n_sub);

    // 곱
    float n_mul = n1 * n2;
    printf("n1 * n2 = %f\n", n_mul);

    // 분
    float n_div = n1 / n2;
    printf("n1 / n2 = %f\n", n_div);
    return 0;

}

int second() {
    char c = 'a';
    printf("Before case change\nc: %c\n", c);

    if (c < 97)
        c = c + 32;
    else
        c = c - 32;

    printf("After case change\nc: %c\n", c);

    return 0;
}

int third() {
    int a = 10, b = 11, c = 0;
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (++a == 11) && (++b == 12);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (a-- == 10) && (b-- == 12);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (a++ == 10) || (b++ == 11);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    c = (--a == 11) || (--b == 11);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    
    int n;
    printf("N을 입력해주세요 : ");
    scanf("%d", &n);

    (n % 2) ?
        printf("N은 짝수, N^3 = %d\n", n * n * n) :
        printf("N은 홀수, N^2 = %d\n", n * n);

    return 0;
}


int fourth() {
    char isLier;

    int Innesim = 9;

    printf("당신은 거짓말을 한 적이 있습니까? (Y/N)\n");
    scanf("%c", &isLier);

    while(1)
    {
        if (isLier == 'Y' || isLier == 'y')
        {
            printf("알고 있었어요.\n");
            break;
        }

        if (Innesim < 0)
        {
            printf("거짓말 치지마요.\n");
            break;
        }

        printf("진짜로 당신은 거짓말을 한 적이 없나요? (Y/N): ");
        scanf(" %c", &isLier);

        // 부정형으로 질문하였으니 한국 문법에 맞게 대답을 역전 시켜준다.
        isLier = (isLier == 'Y' || isLier == 'y') ? 'N' : 'Y';

        Innesim--;
    }

    return 0;
}
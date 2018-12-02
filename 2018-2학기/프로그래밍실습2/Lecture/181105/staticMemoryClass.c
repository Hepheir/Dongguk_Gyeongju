#include <stdio.h>

void function();
static int gValue; // 전역변수는 (static) 값을 따로 초기화 해주지 않으면 0의 값을 가진다.

int main(void) {
    function();
    function();
    function();
    return 0;
}

void function() {
    static int sValue = 0; // static 지역 변수
    auto int aValue = 0;
    // auto 지역 변수. 그동안 써온 변수는 앞에 (auto)가 생략된 것임.
    // 원래 auto를 쓰면 컴파일 에러가 나지만, C버전이 업그레이드 되면서 auto를 표시할 수 있게 됨.
    sValue += 3;
    aValue += 3;
    gValue += 3;
    printf("sValue = %d, aValue = %d\n", sValue, aValue);
    printf("gValue = %d\n", gValue);
    printf("&sValue = %p, &aValue = %p\n", &sValue, &aValue);
    printf("&gValue = %p\n", &gValue);
}
#include <iostream>

using namespace std;

/**
 * 포인터 : 다른 변수의 위치를 가리키는 변수
 * 변수의 타입 뒤에 *를 붙인다.
 * 포인터 변수는 항상 선언하자 마자 초기화한다. (포인터 변수에 메모리를 당장 할당하고 싶지 않다면 nullptr로 초기화한다.)
 * 잘 다루면 괸장히 유용하고 잘못 다루면 망하는 그런 개념
 * */

int main() {
    //* void pointer
    short b = 19;
    int c = 199;

    short* pb = &b;
    // pb = &c;  // int와 short는 다르기 때문에 대입 불가능

    void* pvb = &b;  // 다른 타입의 변수도 담을 수 있다.
    pvb = &c;

    cout << (int*)pvb << " " << *(int*)pvb << endl;  // 보이드 포인터를 사용할 때는 타입을 캐스팅해주어야 한다.
    // 0x7ffeefbff1b4 199

    return 0;
}
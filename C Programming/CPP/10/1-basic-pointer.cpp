#include <iostream>

using namespace std;

/**
 * 포인터 : 다른 변수의 위치를 가리키는 변수
 * 변수의 타입 뒤에 *를 붙인다.
 * 포인터 변수는 항상 선언하자 마자 초기화한다. (포인터 변수에 메모리를 당장 할당하고 싶지 않다면 nullptr로 초기화한다.)
 * 잘 다루면 괸장히 유용하고 잘못 다루면 망하는 그런 개념
 * */

int main() {
    int a = 10;

    // C style, C++ 11 이전 방식
    // int* p = NULL;
    // int* p = 0;

    // Modern (C++ 11)
    int* pa = nullptr;  //* 초기화
    pa = &a;            // 포인터 변수에 변수의 주소를 저장한다.
    // int* pa = &a;
    int& ra = a;  // reference

    cout << "a의 주소 : " << &ra << " a의 포인터 변수의 주소 : " << &pa << " a의 레퍼런스 변수의 주소 : " << &ra << endl;
    // 0x7ffeefbff1b8 0x7ffeefbff1b0 0x7ffeefbff1b8
    //* 레퍼런스 변수는 해당 변수에 대한 별명이라고 생각하면 해당 변수와 같은 주소인 반면에 포인터 변수는 또 다른 메모리 공간을 할당 받는다.
    // 포인터 변수는 변수의 주소를 보관하기 때문에 우체국 직원이라고 생각하면된다. 포인터 변수의 크기는 OS마다 4byte 또는 8byte로 고정된다.
    // 내부적으로 레퍼런스 변수 또한 포인터 변수와 같이 동작한다.

    cout << "a의 포인터 변수의 값 : " << pa << endl;                     // 0x7ffeefbff1b8
    cout << "a의 포인터 변수가 가리키고 있는 변수 a : " << *pa << endl;  // 10

    cout << "a의 포인터 변수의 크기 :  " << sizeof(pa) << endl;  // 8 (MacOS)

    return 0;
}
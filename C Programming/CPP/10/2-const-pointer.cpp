#include <iostream>

using namespace std;

/**
 * 포인터 : 다른 변수의 위치를 가리키는 변수
 * 변수의 타입 뒤에 *를 붙인다.
 * 포인터 변수는 항상 선언하자 마자 초기화한다. (포인터 변수에 메모리를 당장 할당하고 싶지 않다면 nullptr로 초기화한다.)
 * 잘 다루면 괸장히 유용하고 잘못 다루면 망하는 그런 개념
 * */

int main() {
    //* CASE 1
    short b = 19;
    short c = 199;
    const short* pb2 = &b;

    cout << pb2 << " " << *pb2 << " " << sizeof(pb2) << endl;
    // 0x7ffeefbff1a6 19 8

    // *pb2 = 30; // error
    pb2 = &c;

    // a의 주소를 가지고 있던 포인터 변수 p에게 b의 주소를 전달
    cout << pb2 << " " << *pb2 << " " << sizeof(pb2) << endl;
    // 0x7ffeefbff1a4 199 8

    //* CASE 2
    short d = 29;
    short e = 299;
    short* const pd2 = &d;  //* 위치를 바꾼다면??

    cout << pd2 << " " << *pd2 << " " << sizeof(pd2) << endl;
    // 0x7ffeefbff1ae 29 8

    *pd2 = 30;
    // pd2 = &e; // error

    // 값은 변경이 가능하다.
    cout << pd2 << " " << *pd2 << " " << sizeof(pd2) << endl;
    // 0x7ffeefbff1ae 30 8

    //* CASE 3
    short d = 29;
    short e = 299;
    const short* const pd2 = &d;  //* 완전히 바인딩이 된다.

    cout << pd2 << " " << *pd2 << " " << sizeof(pd2) << endl;
    // 0x7ffeefbff1ae 29 8

    // *pd2 = 30; // error
    // pd2 = &e; // error

    return 0;
}
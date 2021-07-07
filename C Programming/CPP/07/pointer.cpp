//* Call(pass) By Value : 값을 넘길 때 새로운 메모리 공간을 만들어서 다른 주소에 변수를 받아 저장한다.

#include <iostream>

using namespace std;

void func(int y) {
    cout << "Y addr : " << &y << endl;  // 0x7ffeefbff1a8
    cout << "In func : " << y << endl;  // 10
    y = 50;
    cout << "In func : " << y << endl;  // 50
}

int main() {
    int x = 10;
    int *px = &x;  // px에 x의 주소를 저장한다.
    int &rx = x;   // x의 별명 rx : 사실은 내부적으로는 포인터로 동작한다. 레퍼런스가 포인터보다 안전하므로 레퍼런스를 쓰자!

    cout << &x << "  " << px << "  " << &rx << endl;  // 0x7ffeefbff1b8  0x7ffeefbff1b8  0x7ffeefbff1b8
    cout << x << "  " << *px << "  " << rx << endl;   // 10  10  10
    cout << &px << endl;                              // 0x7ffeefbff1b0

    *px = 30;
    cout << x << endl;  // 30

    rx = 15;
    cout << x << endl;  // 15

    return 0;
}

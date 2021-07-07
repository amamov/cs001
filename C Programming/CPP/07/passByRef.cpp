//* Call(pass) By Reference : 값을 넘길 떄 따로 메모리 공간을 만들지 않고 메모리 주소를 공유한다.

#include <iostream>

using namespace std;

void func(int &y)  // 변수 X의 alias
{
    cout << "Y addr : " << &y << endl;  // 0x7ffeefbff1b8
    cout << "In func : " << y << endl;  // 10
    y = 50;                             //* X의 주소를 공유하고 있기 때문에 X의 값을 바꾼다.
    cout << "In func : " << y << endl;  // 50
}

int main() {
    int x = 10;

    cout << "X addr : " << &x << endl;  // 0x7ffeefbff1b8
    cout << x << endl;                  // 10

    func(x);  //* Call(pass) By Reference

    cout << x << endl;  //* 50

    return 0;
}

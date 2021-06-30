//* Call(pass) By Value : 값을 넘길 때 새로운 메모리 공간을 만들어서 다른 주소에 변수를 받아 저장한다.

#include <iostream>

using namespace std;

void func(int y)
{
    cout << "Y addr : " << &y << endl; // 0x7ffeefbff1a8
    cout << "In func : " << y << endl; // 10
    y = 50;
    cout << "In func : " << y << endl; // 50
}

int main()
{

    int x = 10;

    cout << "X addr : " << &x << endl; // 0x7ffeefbff17c
    cout << x << endl;                 // 10

    func(x); //* Call(pass) By Value

    cout << x << endl; // 10

    return 0;
}

//* Call(pass) By Value : 값을 넘길 때 새로운 메모리 공간을 만들어서 다른 주소에 변수를 받아 저장한다.

#include <iostream>

using namespace std;

void func()
{
    cout << "hello world!!" << endl;
}

void func(int x)
{
    cout << "hello world!!" << x << endl;
}

int func(float x, float y)
{
    cout << "hello world!!" << x << y << endl;
    return x + y;
}
int defaultFunc(int x = 19)
{
    return x;
}
int func(double x)
{
    cout << "hello world!!" << x << endl;
    return x;
}

int main()
{
    func();
    func(12);
    func(17.77);
    cout << func(12.3f) << endl;
    cout << defaultFunc() << endl;
    return 0;
}

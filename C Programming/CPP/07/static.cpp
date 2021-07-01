#include <iostream>

using namespace std;

void func()
{
    static int count = 0; // static 공간에 저장한다.
    count++;
    cout << count << endl;
}

int main()
{
    func();
    func();
    func();
    func();
    return 0;
}

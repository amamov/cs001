#include <iostream>

using namespace std;

int main()
{
    int a = 0;

    cout << a++ << endl; // 0
    //* cout << a << endl; -> a++

    cout << ++a << endl; // 1
    //* a++ -> cout << a << endl;

    return 0;
}

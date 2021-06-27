#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 20; // * 10 and 20 are literal variable (primary expression) : it has value but no side-effect
    int max;

    cout << sizeof(long) << endl;

    max = (a > b) ? a : b; // 3항 연산자

    cout << max << endl;

    return 0;
}
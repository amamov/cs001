#include <iostream>
using namespace std;

int main()
{
    int a = 10; // * 10 is literal variable (primary expression) : it has value but no side-effect
    a = a + 3;  //* An lvalue can be thought as the destination of a value (왼쪽의 a), an rvalue can be thought as the source of a value (오른쪽의 a).

    int k = 17;
    int &x = k; //* lvalue reference
    // int &x = 17; //* lvalue reference -> error!!
    int &&y = 18; //* rvalue reference -> ok!!

    cout << x << endl;
    cout << y << endl;
    return 0;
}
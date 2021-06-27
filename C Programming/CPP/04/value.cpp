#include <iostream>

using namespace std;

const double PI = 3.14159263; //* global constant 상수
unsigned int n = 7;           //* global variable
unsigned int x;

int main()
{
    unsigned int n = 0; //* local variable;
    unsigned int x;
    int k = 17;
    const double EXP = 2.71818; //* local constant 상수 : local scope의 상수는 무조건 초기화를 해주어야 한다.

    cout << n << endl;   // 0 : 가장 가까운 스코프의 변수를 출력한다.
    cout << ::n << endl; // 7 : 스코프 연산자를 사용하여 스코프를 전역으로 설정한다.
    cout << k << endl;   // 17

    cout << x << endl;   // 69669 : 쓰레기 값이 저장되어 출력된다. 따라서 로컬 변수 선언시에는 초기화를 해주는 것이 좋다.
    cout << ::x << endl; // 0 : global variable의 경우에는 변수 선언시에 0이 자동으로 초기화 된다. (int의 경우)

    cout << PI << endl;  // 3.14159
    cout << EXP << endl; // 2.71818

    return 0;
}
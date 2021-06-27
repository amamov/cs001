#include <iostream>
#include <string>

using namespace std;
// using std::cout; // std::cout을 cout으로 줄인다.

//* x = y + z; : x는 destination, y와 z는 source
//* (중요) short int <= int <= long int : 크기는 플랫폼마다 다르다. signed long int === long int === long : ununtu 64bit에서는 8byte, window 32bit vsc++에서는 4byte

int main()
{
    short int x; // 2 byte
    int a;       // 4 byte : sizeof(int)
    int b;
    int total;
    double doubleVar;       // 8 byte
    const double PI = 3.14; // * constant
    char A = 66;            // * ASCII 문자
    string name = "yoon sang seok";

    cout << sizeof(x) << endl;

    double e = 10.7;
    int f = 2;
    int g = e / f;

    cout << e / f << endl;                      // double
    cout << e / static_cast<double>(f) << endl; // double
    cout << g << endl;                          // int

    cout << 123L << endl; // long
    cout << sizeof(123L) << endl;
    cout << 124.3f << endl; // float
    cout << sizeof(21.45f) << endl;

    std::cout << "hello world" << std::endl; // 문자열
    std::cout << 17 << std::endl;            // 정수
    std::cout << 3.9f << std::endl;          // 실수
    std::cout << "A" << std::endl;           //ascii code

    cout << "hello world" << endl; // 문자열 string
    cout << 17 << endl;            // 정수
    cout << 3.9f << endl;          // 실수
    cout << "A" << endl;           // ascii code

    cout << "a 값 입력" << endl;
    cin >> a;
    cout << "b 값 입력" << endl;
    cin >> b;
    total = a + b;
    cout << "total : " << total << endl;

    return 0;
}

//* cout, cin, endl은 iostream의 인스턴스(객체)이다.
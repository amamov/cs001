//* manipulators : 조정자

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    short x = 43;
    cout << "setw and setfill : " << setw(10) << setfill('#') << x << endl; // setw and setfill : ########43

    int intValue = 11;
    bool boolValue = true;

    cout << showbase;         //* 진법에 따라 접두어를 붙여서 출력하도록 조정 : 8진수는 앞에 0을 붙이고 16진수는 앞에 0x가 붙는다.
    cout << oct;              //* int에 대하여 8진수로 출력하도록 조정
    cout << intValue << endl; // 13 or 013(showbase)
    cout << dec;              //* int에 대하여 10진수로 출력하도록 조정
    cout << intValue << endl; // 11 or 11(showbase)
    cout << hex;              //* int에 대하여 16진수로 출력하도록 조정 : 16진수는 한 자리에 4bit씩 차지한다.
    cout << intValue << endl; // b or 0xb(showbase)

    cout << boolalpha;         //* bool에 대해 true/false가 나오도록한다.
    cout << boolValue << endl; // true
    cout << noboolalpha;       //* bool에 대해 1/0가 나오도록한다. (default)
    cout << boolValue << endl; // true or 0x1(showbase)

    cout << dec;
    //* 3.1142e+002 === 3.1142*10^2
    double doubleValue = 12345.6789;
    double doubleValue2 = 123;
    cout << "doubleValue in fixed_point format : " << doubleValue << endl;               // 12345.7
    cout << "doubleValue in fixed_point format : " << showpoint << doubleValue2 << endl; // 123.000
    cout << "doubleValue in scienific format : " << scientific << doubleValue << endl;   // 1.234568e+04
    cout << "doubleValue in fixed_point format : " << fixed << doubleValue << endl;      // 12345.678900
    cout << fixed << setprecision(2) << "setprecision : " << doubleValue << endl;        //  12345.68

    int binaryLiteral1 = 0b1011;               //* 13(10진수일떄) C++ 14 binary literal : 이진수 형태로 값 입력이 가능하다.
    short binaryLiteral2 = 0b1000000000001111; //* -32753(10진수일때) 이걸 16진수로 표현하면 0X800F로 표현할 수 있다.
    short binaryLiteral3 = 0b1000000000000001; //* -32767(10진수일때)
    cout << binaryLiteral2 << endl;
    cout << binaryLiteral3 << endl;

    return 0;
}
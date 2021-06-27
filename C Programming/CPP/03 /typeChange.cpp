#include <iostream>
#include <typeinfo>

using namespace std;

double add(int x, int y)
{
    return x + y;
}

int main()
{
    bool boolValue = true;
    char charValue = 'A';
    short shortValue = 14;
    float floatValue = 2.9f;
    long longValue = 6;
    int intValue = 7;

    //* [implicit type change] bool < int < unsigned int < long < unsigend long < float < double < long double
    // signed와 unsigned의 크기는 같지만 약속으로 unsigned가 우선적으로 타입 선택이 된다.
    cout << "Type : " << typeid(boolValue + 100).name() << endl;                  // int
    cout << "Type : " << typeid(floatValue + 3.9).name() << endl;                 // double
    cout << "Type : " << typeid(boolValue * intValue + longValue).name() << endl; // long
    // cout << "Type : " << typeid(floatValue = 3.8).name() << endl;                //* float : 실수 주의

    //* [explicit type change]
    // cout << "char에서 int로 형변환 : " << int(charValue) << endl;
    // cout << "char에서 int로 형변환 : " << (int)charValue << endl;              // c style
    cout << "char에서 int로 형변환 : " << static_cast<int>(charValue) << "  " << typeid(static_cast<int>(charValue)).name() << endl; //* c++ style

    //* function typing
    cout << add(12, 17) << " " << typeid(add(12, 17)).name() << endl;

    return 0;
}
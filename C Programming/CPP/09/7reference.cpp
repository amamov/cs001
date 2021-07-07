/*
* 레퍼런스 : 변수의 별명, 객체의 또 다른 이름, 코드에서 다루는 방법은 일반 변수와 같지만 내부적으로는 원본 변수에 대한 포인터로 취급
* 변수의 타입 뒤에 &를 붙인다.
* 레퍼런스 변수는 반드시 초기화 해야 한다. (이렇게 참조 관계가 한 번 정의되면 이를 끊고 다른 변수와 연결이 불가능하다.)
* const 속겅을 부여할 수 있다. (const 속성을 갖는 레퍼런스 변수는 자신의 값을 변경할 수 없게 된다.)
*/

#include <iostream>

using namespace std;

int main() {
    int a = 5, b = 6;

    //* AND 논리 연산자로서
    cout << a << " " << b << " " << (a & b) << endl;  // 5 6 4
    // .... 0101
    // .... 0110
    // &
    // .... 0100 -> 4

    //* 메모리 주소 연산자로서
    cout << &a << " " << &b << endl;  // 0x7ffeefbff194 0x7ffeefbff190

    //* 레퍼런스 변수로서
    double d1 = 3.97;
    double d2 = 4.01;
    double& rd1 = d1;  //* 한 번 바인딩되면 계속 d1에 바인딩된다. constant relation이라고도 함

    cout << "d1 : " << d1 << endl;    // 3.97
    cout << "rd1 : " << rd1 << endl;  // 3.97

    rd1 = 3.5;

    cout << " rd1 = 3.5-> d1 : " << d1 << endl;    // 3.5
    cout << " rd1 = 3.5-> rd1 : " << rd1 << endl;  // 3.5

    rd1 = d2;

    cout << "rd1 = d2-> d1 : " << d1 << endl;    // 4.01
    cout << "rd1 = d2-> rd1 : " << rd1 << endl;  // 4.01

    return 0;
}
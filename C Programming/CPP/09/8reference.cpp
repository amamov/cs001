/*
* 레퍼런스 : 변수의 별명, 객체의 또 다른 이름, 코드에서 다루는 방법은 일반 변수와 같지만 내부적으로는 원본 변수에 대한 포인터로 취급
* 변수의 타입 뒤에 &를 붙인다.
* 레퍼런스 변수는 반드시 초기화 해야 한다. (이렇게 참조 관계가 한 번 정의되면 이를 끊고 다른 변수와 연결이 불가능하다.)
* const 속성을 부여할 수 있다. (const 속성을 갖는 레퍼런스 변수는 자신의 값을 변경할 수 없게 된다.)
* 데이터가 큰 것을 넘길 때 복사(pass by value)로 넘기면 오버헤드가 발생하므로 별칭을 붙여서 바인딩을 시켜서 넘기는 것이 좋다.
*/

#include <iostream>

using namespace std;

void passByValuePlus(int n) {
    n++;
}

void passByRefPlus(int &n) {  // int& n = a; 바인딩
    n++;
    cout << "a에 바인딩된 n의 주소 : " << &n << endl;  // 0x7ffeefbff1a8
}

void constPassByRefPlus(const int &n) {  // int& n = a; 바인딩
    // 넘겨 받은 바인딩된 것을 읽기 용도로만 사용할 때 사용하는 패턴
    cout << "a에 바인딩된 n의 주소 : " << &n << endl;  // 0x7ffeefbff1a8
}

int main() {
    int a = 1;
    cout << a << endl;

    passByValuePlus(a);
    cout << "pass by value : " << a << endl;  // 1

    passByRefPlus(a);
    cout << "pass by ref : " << a << endl;  // 2

    cout << "a의 주소 : " << &a << endl;  // 0x7ffeefbff1a8

    return 0;
}
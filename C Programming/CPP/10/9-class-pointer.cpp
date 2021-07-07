#include <iostream>

using namespace std;

class Friend {
   public:
    int phone;
    Friend* p;  //* Friend 인스턴스를 가리키는 클래스 포인터
};

int main() {
    Friend a, b, c;
    a.phone = 1;
    a.p = &b;
    b.phone = 2;
    b.p = &c;
    c.phone = 3;
    c.p = &a;
    // a는 b를 가리키고 b는 c를 가리키고 c는 b를 가리킨다. 순환 링크드리스트

    cout << "a 번호 : " << a.phone << endl;     // a 번호 : 1
    cout << "b 번호 : " << a.p->phone << endl;  // b 번호 : 2 : (*a.p).phone
    cout << "c 번호 : " << a.p->p->phone << endl;  // c 번호 : 3
    cout << "a 번호 : " << a.p->p->phone << endl;  // a 번호 : 3

    cout << (*a.p).phone << endl;
}
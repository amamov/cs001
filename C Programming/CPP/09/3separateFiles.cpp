/*
* [파일 분할 & 전처리 지시문]
* 파일 분할 시 인터페이스 역할을 할 header 파일, 멤버 함수 정의가 되어 있는 cpp 파일, 그리고 프로그램을 실행하는 cpp 파일로 나눈다.
* 인터페이스 역할을 할 헤더 파일은 확장자가 .h가 붙는다. 나머지 2 파일은 cpp 파일로 확장자를 사용한다.
* 이미 한번 컴파일한 헤더파일을 중복해서 읽어 들이는 문제를 막기 위해 전처리 지시문을 사용한다.
* 전처리 지시문은 define, ifndef, endif 3가지 키워드를 사용한다.

* 실무에서 협업, 유지보수 등의 장점을 살리기 위해 파일을 분할한다.
*/

#include "scv.cpp"
// #include "scv.h"  // 사용자 정의 헤더파일은 <> 대신, ""을 사용한다.

// 일반 함수
void func() {
    SCV s6;
    SCV s7;
    SCV::printSCVCount();
}

int main() {
    SCV s1;
    SCV s2;
    SCV s3("SCV 건설로봇 준비 완료!");

    s1.setHp(60);
    s1.setAttackRate(100);

    SCV::printSCVCount();

    {
        SCV s5("메인 함수 안의 별도의 블럭에서 생성된 객체");
        cout << "아직 블럭 안" << endl;
    }  // 이 시점에 s5의 소멸자가 실행되고 객체가 소멸된다.
    cout << "블럭 밖" << endl;

    cout << "s1의 체력은 : " << s1.getHp() << endl;
    cout << "s1의 공격력은 : " << s1.getAttackRate() << endl;

    func();

    SCV s4(s1);
    cout << "s5의 체력은 : " << s4.getHp() << endl;

    func();

    SCV::printSCVCount();

    return 0;
}

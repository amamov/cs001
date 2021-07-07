/*
* [소멸자]
* 클래스 이름 앞에 ~ 붙여서 사용
* return 값이 없음
* 오버로드 할 수 없음, public 접근 지시어를 적용해야 한다.
* 자원의 정리 (파일 입출력, 동적 메모리 할당)
* 객체가 소멸되는 시점에 시스템이 자동으로 소멸자를 실행시켜 객체를 소멸 시킨다.
* 객체가 소멸되는 시점 : 스코프가 끝날 때
*/

#include <iostream>
#include <string>

using namespace std;

class SCV {
   private:
    int hp;
    int attackRate;

   public:
    SCV();
    SCV(string voiceKor);
    SCV(const SCV &s);

    //* destructor
    ~SCV();

    int getHp();
    void setHp(int value);
    int getAttackRate();
    void setAttackRate(int value);
};

inline SCV::~SCV() {
    cout << "객체가 소멸합니다." << endl;
}

inline SCV::SCV() : hp(60), attackRate(5) {
    cout << "SCV good to go sir!" << endl;
}

inline SCV::SCV(string voiceKor) : hp(60), attackRate(5) {
    cout << voiceKor << endl;
}

inline SCV::SCV(const SCV &s) : hp(s.hp), attackRate(s.attackRate) {
    cout << "SCV good to go sir!" << endl;
    cout << "복사 생성자 할당됨!" << endl;
}

inline int SCV::getHp() {
    return hp;
}

inline void SCV::setHp(int value) {
    hp = value;
}

inline int SCV::getAttackRate() {
    return attackRate;
}

inline void SCV::setAttackRate(int value) {
    attackRate = value;
}

int main() {
    SCV s1;
    SCV s2;
    SCV s3("SCV 건설로봇 준비 완료!");

    s1.setHp(60);
    s1.setAttackRate(100);

    {
        SCV s5("메인 함수 안의 별도의 블럭에서 생성된 객체");
        cout << "아직 블럭 안" << endl;
    }  // 이 시점에 s5의 소멸자가 실행되고 객체가 소멸된다.
    cout << "블럭 밖" << endl;

    cout << "s1의 체력은 : " << s1.getHp() << endl;
    cout << "s1의 공격력은 : " << s1.getAttackRate() << endl;

    SCV s4(s1);
    cout << "s5의 체력은 : " << s4.getHp() << endl;

    return 0;
}

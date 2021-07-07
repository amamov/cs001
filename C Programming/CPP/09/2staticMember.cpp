/*
* [정적 멤버]
* static 키워드 사용
* 정적 멤버 함수 (정적 메서드) 역시 static 키워드를 사용하며 클래스 정의에서 선언
* 정적 멤버 함수 정의 시에는 일반 인스턴스 멤버 함수와 차이가 없음
* 인스턴스 멤버와는 다르게 모든 객체가 공유하는 멤버로 사용
*/

#include <iostream>

using namespace std;

class SCV {
   private:
    // fields (data member)
    int hp;
    int attackRate;

   public:
    //* constructor
    SCV();
    SCV(string voiceKor);
    SCV(const SCV &s);

    //* destructor
    ~SCV();

    //* getter & setter
    int getHp();
    void setHp(int value);
    int getAttackRate();
    void setAttackRate(int value);

   public:
    //* static fields & static method
    // 가독성을 위해 분리한 것
    static int scvCount;
    static void printSCVCount();
};

inline int SCV::scvCount = 0;

// method definition

//* static member function
inline void SCV::printSCVCount() {
    cout << "SCV 객체 수 : " << scvCount << endl;
}

inline SCV::~SCV() {
    scvCount--;
    cout << "객체가 소멸합니다." << endl;
}

inline SCV::SCV() : hp(60), attackRate(5) {
    scvCount++;
    cout << "SCV good to go sir!" << endl;
}

inline SCV::SCV(string voiceKor) : hp(60), attackRate(5) {
    scvCount++;
    cout << voiceKor << endl;
}

inline SCV::SCV(const SCV &s) : hp(s.hp), attackRate(s.attackRate) {
    scvCount++;
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

    SCV::printSCVCount();

    func();

    return 0;
}

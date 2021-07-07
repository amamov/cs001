#include <iostream>
#include <string>

using namespace std;

class SCV {
   private:
    int hp;
    int attackRate;

   public:
    SCV() : hp(60), attackRate(5)  //* initialization list
    {
        cout << "SCV good to go sir!" << endl;
    }

    SCV(string voiceKor) : hp(60), attackRate(5) {
        cout << voiceKor << endl;
    }
    SCV(const SCV &s) : hp(s.hp), attackRate(s.attackRate) {
        cout << "SCV good to go sir!" << endl;
        cout << "복사 생성자 할당됨!" << endl;
    }

    int getHp();
    void setHp(int value);
    int getAttackRate();
    void setAttackRate(int value);
};

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
    SCV s1;  // 객체 생성 시점, 생성자가 없다면 컴파일러가 기본 생성자를 만들어 준다. 생성자가 있다면 생성자 함수를 실행한다.
    SCV s2;
    SCV s3("SCV 건설로봇 준비 완료!");

    s1.setHp(60);
    s1.setAttackRate(100);

    cout << "s1의 체력은 : " << s1.getHp() << endl;            // 60
    cout << "s1의 공격력은 : " << s1.getAttackRate() << endl;  // 60

    SCV s4(s1);  // 복사 생성자
    cout << "s5의 체력은 : " << s4.getHp() << endl;

    return 0;
}

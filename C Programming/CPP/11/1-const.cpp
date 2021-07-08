/*
c++에서는 const 키워드가 여러 용도로 활용이 된다.
1. 변수를 상수로 선언할 때
2. 매개변수에서 값을 전달 받을 때 원본의 값을 readonly로 사용하려고 할 때
3. 복사 생성자에서 사용
4. 멤버 함수 자체에서 멤버 변수의 값을 변경시키고 싶지 않을 때 사용

예외) mutable
*/

#include <iostream>

using namespace std;

class SCV {
   private:
    int hp;
    mutable int mhp;  //* mutable 키워드가 붙은 경우

   public:
    SCV();
    int getHp() const;
    void setHp(int value);
};

inline SCV::SCV() : hp(60) { cout << "SCV good to go sir!" << endl; }
inline int SCV::getHp() const {
    // hp = 500; //* const 키워드로 hp를 변경할 수 없다.
    mhp = 400;  //* mutable 키워드로 선언되어 있기 때문에 const가 붙어도 변경
                //가능하다.
    return hp;
}
inline void SCV::setHp(int value) { hp = value; }

int main() {
    SCV s1;
    s1.setHp(60);

    return 0;
}

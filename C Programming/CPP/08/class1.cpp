#include <iostream>

using namespace std;

//* class에서는 구조체와는 다르게 디폴트로 private 캡슐화가 적용이 된다.

class SCV {
   private:
    int hp;  // 캡슐화

   public:
    int getHp() {
        return hp;
    }
    void setHp(int value) {
        hp = value;
    }
};

int main() {
    SCV s1;
    s1.setHp(60);

    cout << s1.getHp() << endl;  // 60

    return 0;
}
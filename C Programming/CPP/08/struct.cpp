#include <iostream>

using namespace std;

struct SCV {
    int hp;  // attribute, member variable, data member
};

int main() {
    SCV s1;
    s1.hp = 60;  // 구조체에서는 public으로 접근 가능

    cout << s1.hp << endl;

    return 0;
}
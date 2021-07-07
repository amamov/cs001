#include "scv.cpp"

int main() {
    // SCV s[3];
    // SCV s1;

    // SCV::printSCVCount();

    SCV s[3] = {SCV(), SCV("SCV 건설로봇 준비"), SCV()};

    s[1].setHp(25);
    SCV s1(s[2]);

    SCV::printSCVCount();

    for (int k = 0; k < 3; k++) {
        cout << s[k].getHp() << endl;
    }

    return 0;
}
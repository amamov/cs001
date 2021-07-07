#include <iostream>

using namespace std;

int main() {
    int cppScores[] = {7, 2};

    cout << cppScores[1] << endl;

    for (int k = 0; k < sizeof(cppScores) / sizeof(cppScores[0]); k++) {
        cout << cppScores[k] << endl;
        cout << &cppScores[k] << endl;  // 연속된 공간에서 4byte씩 차이가 나는 것을 확인할 수 있다.
    }

    // cppScores[2] = 3; // error

    return 0;
}
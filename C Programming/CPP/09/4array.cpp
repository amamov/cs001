#include <iostream>

using namespace std;

int main() {
    const int MAX = 3;
    int cppScores[MAX];  // 크기가 3개인 int 타입의 배열을 선언
    short int helloArray[MAX] = {24, 21, 29};
    // short int helloArray[MAX] = { 99 }; // [99, 0, 0]으로 저장됨

    // 연속된 4byte 공간에 각각 할당
    cppScores[0] = 24;
    cppScores[1] = 21;
    cppScores[2] = 29;

    cout << cppScores[1] << endl;

    for (int k = 0; k < MAX; k++) {
        cout << cppScores[k] << endl;
        cout << &cppScores[k] << endl;  // 연속된 공간에서 4byte씩 차이가 나는 것을 확인할 수 있다.
    }

    for (int k = 0; k < MAX; k++) {
        cout << helloArray[k] << endl;
        cout << &helloArray[k] << endl;  // 연속된 공간에서 2byte씩 차이가 나는 것을 확인할 수 있다.
    }

    return 0;
}
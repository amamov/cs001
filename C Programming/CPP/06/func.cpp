#include <cmath>
#include <iostream>

using namespace std;

int total(int x, int y) {
    return x + y;
}

int protofunc(int x);  // 프로토 타입

int main() {
    const double PI = 3.14159226;
    double degree = PI / 4;

    cout << cos(degree) << endl;    // 0.707107
    cout << total(18, 10) << endl;  // 28

    char ch;
    int count = 0;
    while (cin >> noskipws >> ch) {
        if (isalpha(ch))  // 알파벳인지 체크
        {
            count++;
        }
        ch = toupper(ch);  // 대문자로 변환
        cout << ch;
    }

    cout << "앒파벳 문자의 개수 : " << count << endl;

    return 0;
}

int protofunc(int x) {
    return x;
}
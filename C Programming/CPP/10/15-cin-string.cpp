#include <iostream>
#include <string>

using namespace std;

/**
 * 문자열
 * */

int main() {
    char cs[5];
    string s;

    cin.getline(cs, 5);  // 초과 입력시 fail
    cin.clear();         // cin 초기화

    // cin >> s;
    getline(cin, s);  // 띄어쓰기까지 받을 수 있도록 한다.

    cout << cs << endl;
    cout << s << endl;

    return 0;
}
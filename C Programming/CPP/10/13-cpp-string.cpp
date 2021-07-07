#include <iostream>
#include <string>

using namespace std;

/**
 * 문자열
 * C++ Style : 클래스, 객체, string
 * */

int main() {
    string s = "yoon";
    string t;

    t = s;
    cout << "source : " << s << endl;
    cout << "target : " << t << endl;
    cout << "size : " << s.size() << endl;

    return 0;
}
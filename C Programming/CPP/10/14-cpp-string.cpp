#include <iostream>
#include <string>

using namespace std;

/**
 * 문자열
 * */

int main() {
    string s = "yoon";
    string t = "sangseok";

    t = s + t;

    if (t == "yoonsangseok") {
        cout << t << endl;
    }

    return 0;
}
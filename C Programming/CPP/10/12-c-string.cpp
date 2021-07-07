#include <cstring>  // c언어의 string.h
#include <iostream>

using namespace std;

/**
 * 문자열
 * C Style : 함수, char array[], char* array  사용
 * */

int main() {
    char s[] = "yoon";

    int len = strlen(s);  // string length

    char* t = new char[len + 1];  // dynamic allocation

    strcpy(t, s);  // string copy

    cout << "source = " << s << endl;
    cout << "target = " << t << endl;

    delete[] t;  // free memory
    t = nullptr;

    return 0;
}
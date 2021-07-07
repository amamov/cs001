#include <iostream>

using namespace std;

/**
 * 메모리 관리
 * 메모리 영역 (code, static, stack, heep)
 * code : 프로그램 코드
 * static : 전역객체 및 정적객체
 * stack : 지역변수 및 매개변수
 * heap : 동적 메모리 할당
 * */

char* reverseWords(const char* src, int len) {
    char* r = new char[len + 1];
    for (int k = 0; k < len; k++) {
        r[k] = src[len - k - 1];
    }
    r[len] = 0;
    return r;
}

int main() {
    char word[] = "Yoon";
    char* rword = reverseWords(word, 3);

    cout << word << endl;
    cout << rword << endl;

    delete[] rword;
    rword = nullptr;

    return 0;
}
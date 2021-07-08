#include <iostream>
#include <string>

// 이 코드의 경우 예상치 못한 메모리 누수 현상이 발생된다.

using namespace std;

void go() { throw "go 함수 안에서 강제 예외 발생"; }

void func() {
    try {
        int* a = nullptr;
        a = new int[3];
        cout << "동적 할당 완료";
        go();
        cout << "자원 해제 완료";
        delete[] a;
    } catch (const char* error) {
        cout << "예외 처리" << endl;
        cout << error;
    }
}

int main() {
    func();

    return 0;
}
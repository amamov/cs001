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

int a = 1;

int main() {
    int humans;
    int* arr = nullptr;

    cout << "몇 명 ? :";
    cin >> humans;

    arr = new int[humans];  // dynamic memory allocation (heap memory)
    // new : 매모리가 할당된 주소를 반환한다. 만약 humans가 3이라면
    // 12byte를 확보를 한다.

    for (int i = 0; i < humans; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < humans; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr;  //* 해당 메모리 해제를 해주어야 한다.
    // 만일, new short 3;로 하나의 공간만 사용을 하였다면, delete var 이런식으로
    // 해제한다.

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    //* 배열 전체를 가리키는 포인터를 배열 포인터라고 한다.

    short myArr[5] = {-1, 21, 54, 23, 44};
    short(*p)[5] = &myArr;  //* 배열 포인터

    (*p)[2] = 7;

    cout << myArr[2] << endl;  // 7

    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int arr[5];
    int* parr = &arr[3];

    // 1 2 3 4 5 6 7 8 9 10(a) 11(b) 12(c) 13(d) 14(e) 14(f) 15(g) 16(10) 17(11)
    // ...

    cout << parr << " === " << &arr[3] << endl;
    // 0x7ffeefbff18c === 0x7ffeefbff18c

    parr++;  // 4byte 증가
    cout << sizeof(parr) << endl;

    cout << parr << " === " << &arr[4] << endl;
    // 0x7ffeefbff190 === 0x7ffeefbff190

    //* short로 담는다면 2byte씩 증가

    short myArr[5] = {-1, 21, 54, 23, 44};
    short* pMyArr = &myArr[1];

    cout << pMyArr << " " << &myArr[1] << endl;
    cout << *pMyArr << " " << myArr[1] << endl;  // 21
    pMyArr++;
    cout << pMyArr << " " << &myArr[2] << endl;
    cout << *pMyArr << " " << myArr[2] << endl;  // 54

    //* 포인터로 배열 순회
    pMyArr = &myArr[0];
    for (int i = 0; i < sizeof(myArr) / sizeof(myArr[0]); i++) {
        cout << *pMyArr << " " << endl;
        pMyArr++;
    }

    pMyArr = &myArr[0];
    for (int i = 0; i < sizeof(myArr) / sizeof(myArr[0]); i++) {
        cout << *(pMyArr + i) << " " << endl;
    }

    pMyArr = &myArr[0];
    for (int i = 0; i < sizeof(myArr) / sizeof(myArr[0]); i++) {
        cout << pMyArr[i] << " " << endl;
    }

    //* 배열을 포인터처럼 사용
    for (int i = 0; i < sizeof(myArr) / sizeof(myArr[0]); i++) {
        cout << *(myArr + i) << " " << endl;
    }

    return 0;
}
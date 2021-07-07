#include <iostream>

using namespace std;

int main() {
    //* 포인터 배열 : 각 원소가 포인터 변수인 배열

    double x = 1.7, y = 1.8, z = 3.9;
    double* parr[3];  // 포인터 배열

    parr[0] = &x;
    parr[1] = &y;
    parr[2] = &z;

    for (int i = 0; i < sizeof(parr) / sizeof(*(parr[2])); i++) {
        cout << *(parr[i]) << endl;
    }

    return 0;
}
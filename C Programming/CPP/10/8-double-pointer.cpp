#include <iostream>

using namespace std;

int main() {
    //* 이중 포인터 : 포인터의 포인터

    int x = 19;
    int* px = &x;
    int** ppx = &px;  // 이중 포인터

    cout << **ppx << endl;  // 19

    cout << *ppx << " == " << px << " == " << &x << endl;

    return 0;
}
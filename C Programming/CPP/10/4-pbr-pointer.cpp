#include <iostream>

using namespace std;

//* pass by reference
void add(int* n) {  // int* n = &x;
    *n = *n + 2;

    cout << n << endl;   // 0x7ffeefbff1b8
    cout << &n << endl;  // 0x7ffeefbff188
    cout << *n << endl;  // 21
}

int main() {
    int x = 19;

    cout << x << endl;  // 19

    add(&x);

    cout << x << endl;  // 21

    return 0;
}
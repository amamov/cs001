//* Call(pass) By Value : 값을 넘길 때 새로운 메모리 공간을 만들어서 다른 주소에 변수를 받아 저장한다.

#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
    int tmp = 0;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main()
{

    int x = 1;
    int y = 2;

    swap(&x, &y);

    cout << x << " " << y << endl;

    return 0;
}

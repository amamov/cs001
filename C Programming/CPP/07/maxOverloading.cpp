//* Call(pass) By Value : 값을 넘길 때 새로운 메모리 공간을 만들어서 다른 주소에 변수를 받아 저장한다.

#include <iostream>

using namespace std;

int max(int x, int y)
{
    if (x < y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

int max(int x, int y, int z)
{
    return max(max(x, y), z);
}

int main()
{
    cout << max(1, 4, 10) << endl;
    return 0;
}

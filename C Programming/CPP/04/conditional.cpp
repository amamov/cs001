#include <iostream>

using namespace std;

int main()
{
    int a = 17, b = 3, max = 0;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

    cout << max << endl;

    double k = 3.11;
    //* k == 3.11 이러한 조건문은 피하는 것이 좋다. 부동 소수점 같은 경우는 메모리에 저장된 값의 정밀도를 모르기 때문이다. 결과는 system에 따라 다르게 나온다.

    //* 5.0 <= 5 -> type이 다르므로 promotion이 일어난다. 따라서 5.0 <= 5.0으로 계산된다.
    //* 3 < 4 == 1 -> 우선순위 처리로 true이다.

    return 0;
}
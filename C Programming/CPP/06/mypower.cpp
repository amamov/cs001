#include <iostream>

using namespace std;

int power(int down, int up)
{
    int result = down;
    for (int i = 1; i < up; i++)
    {
        result *= down;
    }
    return result;
}

int main()
{
    cout << power(2, 4) << endl;
    return 0;
}
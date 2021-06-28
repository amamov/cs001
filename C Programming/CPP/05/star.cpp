#include <iostream>

using namespace std;

int main()
{
    int n = 5;

    cout << "------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j > 1; j--)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << "*";
        }
        for (int k = 0; k < i; k++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
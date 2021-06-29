#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int number = rand();
    cout << number << endl;
    return 0;
}